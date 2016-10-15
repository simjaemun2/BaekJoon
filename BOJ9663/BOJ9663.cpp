#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

int table[15]={	1
, 0
, 0
, 2
, 10
, 4
, 40
, 92
, 352
, 724
, 2680
, 14200
, 73712
, 365596
, 2279184};

int N;


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
		cin >> N;



		cout << table[N-1] << endl;
	}

	return 0;
}