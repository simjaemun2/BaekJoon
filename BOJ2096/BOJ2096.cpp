#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int input[3];
int cacheMin[3];
int cacheMax[3];
int N;


int main(int argc, char** argv)
{

	std::ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	scanf("%d", &N);

	for (int i = 0; i<N; i++)
	{
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		int t0 = cacheMax[0];
		int t1 = cacheMax[1];
		int t2 = cacheMax[2];
		cacheMax[0] = max(t0,t1) + input[0];
		cacheMax[1] = max({t0,t1,t2}) + input[1];
		cacheMax[2] = max(t1, t2) + input[2];
		t0 = cacheMin[0];
		t1 = cacheMin[1];
		t2 = cacheMin[2];
		cacheMin[0] = min(t0, t1) + input[0];
		cacheMin[1] = min({ t0,t1,t2 }) + input[1];
		cacheMin[2] = min(t1, t2) + input[2];

	}

	printf("%d %d", max({ cacheMax[0],cacheMax[1],cacheMax[2] }), min({ cacheMin[0],cacheMin[1],cacheMin[2] }));


	return 0;
}