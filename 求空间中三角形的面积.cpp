#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
struct Point 
{
	double x, y, z;
	char c;
}point[60];

double getL(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

inline double GetArea(Point a, Point b, Point c)
{
	if ((a.c == b.c && a.c == c.c) || ((a.c != b.c && a.c != c.c && c.c != b.c)))
	{
		double a1 = getL(a, b);
		double a2 = getL(a, c);
		double a3 = getL(b, c);
		double p = (a1 + a2 + a3) * 0.5;
		double S = (p * (p - a1) * (p - a2) * (p - a3));
		if (S < 0) return 0;
		S = sqrt(S);
		return S;
	}
	else
		return 0;
}

void solve()
{
	double ans = 0.0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = i + 1; j < N; j++) 
		{
			for (int k = j + 1; k < N; k++) 
			{
				ans = max(ans, GetArea(point[i], point[j], point[k]));
			}
		}
	}
	printf("%.5f\n", ans);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> point[i].c >> point[i].x >> point[i].y >> point[i].z;
	}
	solve();
	return 0;
}