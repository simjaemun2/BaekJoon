#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_NUM 9
#define SEG_NUM 7

#define LEN 3


char* segments[MAX_NUM + 1] =
{
	"1110111",//0
	"0010010",//1
	"1011101",//2
	"1011011",//3
	"0111010",//4
	"1101011",//5
	"1101111",//6
	"1110010",//7
	"1111111",//8
	"1111011"//9
};

char input[SEG_NUM + 1];

//set : ������ �ڸ��� ����
//num : �ڸ��� ������ �̿��� ���� ��� ����
int aSet[LEN][MAX_NUM + 1];
int aSetCnt[LEN];
int bSet[LEN][MAX_NUM + 1];
int bSetCnt[LEN];

int aNum[1000];
int aNumCnt;

int bNum[1000];
int bNumCnt;

int ab[1000000];
int stack[1000000];
int abCnt;

bool cCache[LEN * 2][MAX_NUM + 1];

void getABSetAndNum()
{
	//A �� �ڸ������� ������ ���� ������ ã��
	for (int i = 0; i < LEN; i++)
	{
		cin >> input;

		aSetCnt[i] = 0;

		for (int j = 0; j <= MAX_NUM; j++)
		{
			int k;

			for (k = 0; k < SEG_NUM; k++)
			{
				if (input[k] > segments[j][k])
					break;
			}

			if (k == SEG_NUM)
			{
				aSet[i][aSetCnt[i]++] = j;
			}
		}
	}

	//B �� �ڸ������� ������ ���� ������ ã��
	for (int i = 0; i < LEN; i++)
	{
		cin >> input;

		bSetCnt[i] = 0;

		for (int j = 0; j <= MAX_NUM; j++)
		{
			int k;

			for (k = 0; k < SEG_NUM; k++)
			{
				if (input[k] > segments[j][k])
					break;
			}

			if (k == SEG_NUM)
			{
				bSet[i][bSetCnt[i]++] = j;
			}
		}
	}

	//A ���� ������ �̿��� ��¥ ���ڸ� ����
	aNumCnt = 0;
	for (int i = 0; i < aSetCnt[0]; i++)
	{
		for (int j = 0; j < aSetCnt[1]; j++)
		{
			for (int k = 0; k < aSetCnt[2]; k++)
			{
				aNum[aNumCnt++] = aSet[0][i] * 100 + aSet[1][j] * 10 + aSet[2][k];
			}
		}
	}

	//B ���� ������ �̿��� ��¥ ���ڸ� ����
	bNumCnt = 0;
	for (int i = 0; i < bSetCnt[0]; i++)
	{
		for (int j = 0; j < bSetCnt[1]; j++)
		{
			for (int k = 0; k < bSetCnt[2]; k++)
			{
				bNum[bNumCnt++] = bSet[0][i] * 100 + bSet[1][j] * 10 + bSet[2][k];
			}
		}
	}

}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int l, int h)
{
	int i = l - 1;
	int x = arr[h];

	for (int j = l; j < h; j++)
	{
		if (x > arr[h])
		{
			swap(arr[++i], arr[j]);
		}
	}

	swap(arr[++i], arr[h]);

	return i;
}

void qsort(int arr[], int l, int h)
{
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;

	while (top >= 0)
	{
		h = stack[top--];
		l = stack[top--];

		int p = partition(arr, l, h);

		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

void getAmulB()
{
	abCnt = 0;

	for (int a = 0; a < aNumCnt; a++)
	{
		for (int b = 0; b < bNumCnt; b++)
		{
			ab[abCnt++] = aNum[a] * bNum[b];
		}
	}

	//���� a*b ������ C�� ���ϱ� ���� ����
	qsort(ab, 0, abCnt - 1);
}

void getCSet()
{
	//C �� �ڸ������� ������ ���� ������ ã��
	//A,B ó�� ���ڸ� ���� �������� �ʰ�,  cache ����� �̿�
	for (int i = 0; i < LEN*2; i++)
	{
		for (int j = 0; j <= MAX_NUM; j++)
		{
			cCache[i][j] = false;
		}

		cin >> input;

		for (int j = 0; j <= MAX_NUM; j++)
		{
			int k;

			for (k = 0; k < SEG_NUM; k++)
			{
				if (input[k] > segments[j][k])
					break;
			}

			if (k == SEG_NUM)
			{
				cCache[i][j] = true;
			}
		}
	}
}

int getAnswer()
{	
	//a*b �� ��, ���� ������ C�� ��
	for (int i = 0; i < abCnt; i++)
	{
		int num = ab[i];

		int j;


		//1�� �ڸ����� ������������ �ڸ��� Ž��
		for (int j = 5; j >= 0; j--)
		{
			int d = num % 10;
			
			//� �ڸ����� cache�� ����� ���� �ƴ� ��, �ݺ��� ����
			if (cCache[j][d] == false)
				break;
		}

		if (j == -1)
		{
			//��
			return num;
		}
	}

	return -1;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> T;

	for (tc = 0; tc < T; tc++)
	{
		getABSetAndNum();
		getAmulB();
		getCSet();
		cout << getAnswer() << endl;
	}

	return 0;
}