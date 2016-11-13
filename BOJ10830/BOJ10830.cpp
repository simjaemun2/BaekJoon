#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>


using namespace std;

#define MOD 1000

int N;
long long int B;

vector<vector<int> > mulMatrix(vector<vector<int> >& a, vector<vector<int> >& b)
{
	vector<vector<int> > result(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= MOD;
			}
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> B;

		vector<vector<int> > input(N, vector<int>(N));
		vector<vector<int> > result(N, vector<int>(N));

		for (int i = 0; i<N; i++)
		{
			
			for (int j = 0; j < N; j++)
			{
				cin >> input[i][j];

				if (i == j)
				{
					result[i][j] = 1;
				}
				else
				{
					result[i][j] = 0;
				}
			}
		}

		while (B > 0)
		{
			if (B & 1)
			{
				result = mulMatrix(result, input);
			}
			input = mulMatrix(input, input);

			B /= 2;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}