#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX_N
#define INF 2000000000
#define MOD

int N;
priority_queue<int > maxHeap;
priority_queue<int , vector<int >, greater<int > > minHeap;

int main(int argc, char** argv)
{
	int tc, T;
#ifdef _WIN32
	freopen("Text.txt", "r", stdin);
#endif

	//cin >> T;
	T = 1;
	for (tc = 0; tc < T; tc++)
	{
		//cin >> N;
		scanf("%d", &N);
		int a;
		//cin >> a;
		scanf("%d", &a);

		//cout << a << endl;
		printf("%d\n", a);

		minHeap.push(a);

		for (int i = 1; i<N; i++)
		{
//			cin >> a;
			scanf("%d", &a);

			minHeap.push(a);

			if (maxHeap.size() < minHeap.size())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}

			while (maxHeap.top() > minHeap.top())
			{
				int maxTop = maxHeap.top();
				int minTop = minHeap.top();
				maxHeap.pop();
				minHeap.pop();

				maxHeap.push(minTop);
				minHeap.push(maxTop);
			}
			//cout << maxHeap.top() << endl;
			printf("%d\n", maxHeap.top());
		}
	}

	return 0;
}