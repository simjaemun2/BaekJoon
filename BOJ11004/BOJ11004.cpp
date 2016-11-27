#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 5000000

int N,K;
int input[MAX_N];

int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> N >> K;


	for (int i = 0; i<N; i++)
	{
		cin >> input[i];
	}

	nth_element(input, input + K - 1, input + N);
	
	cout << input[K - 1];


	return 0;
}