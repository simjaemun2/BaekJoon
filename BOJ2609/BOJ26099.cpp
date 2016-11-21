#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>

using namespace std;

int A,B;

int getGCD(int a, int b)
{
	if (a < b)
		return getGCD(b, a);
	if (b == 0)
		return a;

	return getGCD(b, a%b);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	cin >> A >> B;
	
	int gcd = getGCD(A, B);

	cout << gcd << endl;
	cout << A / gcd * B;


	return 0;
}