#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void make_next(string &s, vector<int> &next)
{
	int len = s.size();
	next[0] = 0;
	int k = 0;
	for (int i = 1; i < len; ++i)
	{
		while (k > 0 && s[i] != s[k])
			k = next[k - 1];
		if (s[i] == s[k])
			++k;
		next[i] = k;
	}
}

int kmp(string &s, string &d)
{
	int len = s.size();
	vector<int> next(len, 0);
	make_next(s, next);
	int k = 0;
	for (int i = 0; i < len; ++i)
	{
		while (k > 0 && s[i] != d[k])
			k = next[k - 1];
		if (s[i] == d[k])
			++k;
		if (k == d.size())
		{
			return i - k + 1;
		}
	}
	return -1;
}