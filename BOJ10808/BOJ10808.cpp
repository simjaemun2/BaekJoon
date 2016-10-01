#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

#define MAX_LEN 100
char input[MAX_LEN + 1];
char cache[127];

int main(int argc, char** argv)
{
	int tc, T;
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r",
		stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{

		cin >> input;
		
		for (int i = 0; input[i] != 0; i++)
		{
			cache[input[i]]++;
		}

		for (int i = 'a'; i <= 'z'; i++)
		{
			cout << (int)(cache[i]) << " ";
			cache[i] = 0;
		}
		cout << endl;

		//cout <<  << endl;
	}

	return 0;
}