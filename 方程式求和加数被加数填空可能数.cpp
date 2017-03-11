#include<iostream>
#include<cstdio>
#include<vector>
#include <string>
using namespace std;
int T;
int to(string s, int x)
{
	for (int i=s.size()-1; i>=0; --i)
	{
		if (s[i] == 'X')
		{
			int temp = x % 10;
			if (temp == 0) return -1;
			x /= 10;
			s[i] = char('0'+(temp-0));
		}
	}
	return std::atoi(s.c_str());
}
int main()
{
	cin >> T;
	int tt = T;
	while (tt--)
	{
		string add1, add2, sum;
		cin >> add1 >> add2 >> sum;
		int intsum = std::atoi(sum.c_str());
		int ans = 0;
		int n1 = 0;
		int n2 = 0;
		for (int i = 0; i < add1.size(); ++i)
		{
			if (add1[i] == 'X') ++n1;
		}
		for (int i = 0; i < add2.size(); ++i)
		{
			if (add2[i] == 'X') ++n2;
		}
		int add1in = std::atoi(add1.c_str());
		int add2in = std::atoi(add2.c_str());
		int nn1 = n1;
		int nn2 = n2;
		int maxn1 = 9;
		int maxn2 = 9;
		while (n1--)
		{
			maxn1 = (maxn1 * 10 + 9);
		}
		maxn1 /= 10;
		while (n2--)
		{
			maxn2 = (maxn2 * 10 + 9);
		}
		maxn2 /= 10;
		if (nn1 == 0 && nn2 == 0)
		{
			if (add1in + add2in == intsum)
				ans = 1;
			else
				ans = 0;
		}
		else if (nn1 == 0)
		{
			for (int j = 1; j <= maxn2; ++j)
			{
				int in2 = to(add2, j);
				if (in2 == -1) continue;

				if (add1in + in2 == intsum)
				{
					++ans;
				}
			}
		}
		else if(nn2 == 0)
		{
			for (int i = 1; i <= maxn1; ++i)
			{
				int in1 = to(add1, i);
				if (in1 == -1) continue;
				if (in1 + add2in == intsum)
				{
					++ans;
				}
			}
		}

		else
		{
			for (int i = 1; i <= maxn1; ++i)
			{
				int in1 = to(add1, i);
				if (in1 == -1) continue;
				for (int j = 1; j <= maxn2; ++j)
				{
					int in2 = to(add2, j);
					if (in2 == -1) continue;
					if (in1 + in2 == intsum)
					{
						++ans;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}