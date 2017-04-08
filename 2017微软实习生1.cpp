/*
八皇后判断同一行同一列同一斜线(斜率1和-1)的点对数，O(n)时间。
用map映射把横纵坐标映射到x,y轴，斜率映射到x轴。
*/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int, int> ver;
map<int, int> hor;
map<int, int> dia1;
map<int, int> dia2;
int N;
int a, b;
int ans;
int main()
{
	cin >> N;
	ans = 0;
	while (N--)
	{
		scanf("%d%d", &a, &b);
		ans = ans + ver[a] + hor[b] + dia1[a - b] + dia2[a + b];
		++ver[a];
		++hor[b];
		++dia1[a - b];
		++dia2[a + b];
	}
	cout << ans << endl;
	return 0;
}