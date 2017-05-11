/*
沈学姐和她的男朋友去丽江旅游，在酒吧里，他们玩起了“谁是卧底”。几轮下来，学姐了解了一些信息，她想知道通过这些信息能否推断出每一个人的所属阵营。 

注：“谁是卧底”中共有3个阵营：村民，白板，卧底。分别用1，2，3表示。 
第一行一个整数T，表示有T组数据。 

对于每组数据： 

第一行为两个整数n，m，表示游戏人数和信息条数。(n<=2000,m<=10000) 

接下来m行每行三个整数k，x，y。(k=1或2) 

k=1时表示标号x的人和标号y的人是同一阵营。 

K=2时表示标号x的人属于y阵营。(1<=y<=3) 

数据保证不会有人同时属于多个阵营。 
*/


#include <cstdio>  
#include <queue>  
#include <vector>  
#include <iostream>
#include <set>
using namespace std;
int T;
int n, m;
int i, j;
int k, x, y;
struct XY
{
	int x, y, k = 0;
};

struct Node
{
	int value = 0;
	Node *father;
}node[2005];

Node nnode[4];

Node* findf(Node *no)
{
	while (no->father != NULL && no->father != no)
	{
		no = no->father;
	}
	return no;
}
int findv(Node *no)
{
	while (no->father != NULL && no->father != no)
	{
		no = no->father;
	}
	return no->value;
}
int main()
{
	int t = 1;
	nnode[1].value = 1;
	nnode[1].father = NULL;
	nnode[2].value = 2;
	nnode[2].father = NULL;
	nnode[3].value = 3;
	nnode[3].father = NULL;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for (i = 0; i <= n; ++i)
		{
			node[i].value = 0;
			node[i].father = &node[i];
		}
		vector<XY> info(m + 5);

		for (i = 0; i < m; ++i)
		{
			cin >> k >> x >> y;
			info[i].x = x;
			info[i].y = y;
			info[i].k = k;
		}
		for (auto inf : info)
		{
			if (inf.k == 2)
			{
				if (inf.y == 1)
				{
					node[inf.x].father = &nnode[1];
				}
				if (inf.y == 2)
				{
					node[inf.x].father = &nnode[2];
				}
				if (inf.y == 3)
				{
					node[inf.x].father = &nnode[3];
				}
			}
		}
		for (auto inf : info)
		{
			if (inf.k == 1)
			{
				if (findv(&node[inf.x]) > 0)
				{
					findf(&node[inf.y])->father = &nnode[findv(&node[inf.x])];
					continue;
				}
				else if (findv(&node[inf.y]) > 0)
				{
					findf(&node[inf.x])->father = &nnode[findv(&node[inf.y])];
					continue;
				}
				node[inf.x].father = &node[inf.y];
			}
		}
		bool flag = true;
		for (i = 1; i <= n; ++i)
		{	
			if (findv(&node[i]) == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("Case #%d:YES\n", t);
		}
		else
		{
			printf("Case #%d:NO\n", t);
		}
		++t;
	}
	return 0;
}