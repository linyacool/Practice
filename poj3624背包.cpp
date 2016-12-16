#include<cstdio>
#include<iostream>
using namespace std;
int N, M;
int i, j;
short w[3500], d[3500], m[12881];
int max(int a, int b)
{
	return a>b ? a : b;
}
int min(int a, int b)
{
	return a<b ? a : b;
}
int main()
{
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d%d", &w[i], &d[i]);
	}
	for (i = N; i >= 1; --i) //顺序无关
	{
		for (j = M; j >= w[i]; --j)
		{
			m[j] = max(m[j], m[j - w[i]] + d[i]);
		}
	}

	printf("%d", m[M]);
	//scanf("%d", &M);
	return 0;
}