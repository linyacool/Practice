/*
有N个任务，每个任务花费1个机器人1小时的时间，每个机器人可花费Q小时复制一个机器人.
求最短的任务完成时间.
1<=N<=10^12, 1<=Q<=1000
*/
#include <iostream>
#include <cstdio>
using namespace std;
long long N, Q;
long long temp;
long long ans = 0;
long long minn;
int main()
{
	scanf("%lld%lld", &N, &Q);
	minn = (1 << 30);
	for (int i = 0; i < 40; ++i)
	{
		temp = ((long long) (1) << i);
		if (temp == 1)
			ans = 0;
		else
			ans = i * Q;
		ans += N / temp + (N % temp > 0 ? 1 : 0);
		if (ans < minn) minn = ans;
	}
	printf("%lld", minn);
	return 0;
}