//poj 1287
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXNUM = 6000;
int N, E;
int i, j, k;
int pre[MAXNUM];
struct node
{
	int x;
	int y;
	int val;
}a[MAXNUM];

int find(int p)
{
	while (p != pre[p]) p = pre[p];
	return p;
}
int cmp(const void *p1, const void *p2)
{
	return ((node*)p1)->val - ((node*)p2)->val;
}

int main()
{
	while (scanf("%d", &N) && N != 0)
	{
		scanf("%d", &E);
		for (i = 0; i < E; ++i)
		{
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].val);
		}
		qsort(a, E, sizeof(node), cmp);
		int ans = 0;
		int cnt = 0;
		for (i = 0; i < N; ++i)
			pre[i] = i;
		for (i = 0; i < E; ++i)
		{
			int f1 = find(a[i].x);
			int f2 = find(a[i].y);
			if (f1 != f2)
			{
				++cnt;
				ans += a[i].val;
				pre[f2] = f1;
				if (cnt == N - 1)
					break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}