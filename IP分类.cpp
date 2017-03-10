#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct IP
{
	int ip1;
	int ip2;
	int ip3;
	int ip4;
	IP(int i1, int i2, int i3, int i4) :ip1(i1), ip2(i2), ip3(i3), ip4(i4) {}
};
vector<IP> ip;
bool cmp(const IP ip1, const IP ip2)
{
	if (ip1.ip1 < ip2.ip1) return true;
	if (ip1.ip1 > ip2.ip1) return false;
	if (ip1.ip2 < ip2.ip2) return true;
	if (ip1.ip2 > ip2.ip2) return false;
	if (ip1.ip3 < ip2.ip3) return true;
	if (ip1.ip3 > ip2.ip3) return false;
	if (ip1.ip4 < ip2.ip4) return true;
	if (ip1.ip4 > ip2.ip4) return false;
	return false;
}
char ipclass(IP ip)
{
	int seg3 = ip.ip1;
	if (seg3 < 128)
		return 'A';
	else if (seg3 < 192)
		return 'B';
	else if (seg3 < 224)
		return 'C';
	else if (seg3 < 240)
		return 'D';
	else
		return 'E';
}
int main()
{
	int i1, i2, i3, i4;
	int tt = 5;
	while (tt--)
	{
		scanf("%d.%d.%d.%d", &i1, &i2, &i3, &i4);
		if (i1 > 255 || i2 > 255 || i3 > 255 || i4 > 255) continue;
		ip.push_back({ i1,i2,i3,i4 });
	}
	int n = ip.size();
	sort(ip.begin(), ip.end(), cmp);
	vector<IP> ipa, ipb, ipc, ipd, ipe;
	for (auto &ipip : ip)
	{
		if (ipclass(ipip) == 'A')
		{
			ipa.push_back(ipip);
		}
		if (ipclass(ipip) == 'B')
		{
			ipb.push_back(ipip);
		}
		if (ipclass(ipip) == 'C')
		{
			ipc.push_back(ipip);
		}
		if (ipclass(ipip) == 'D')
		{
			ipd.push_back(ipip);
		}
		if (ipclass(ipip) == 'E')
		{
			ipe.push_back(ipip);
		}
	}
	if (ipa.size() != 0)
	{
		cout << "A:[";
		bool flag = true;
		for (auto &ipip : ipa)
		{
			if (flag == false)
			{
				cout << ',';
			}
			flag = false;
			cout << ipip.ip1 << '.' << ipip.ip2 << '.' << ipip.ip3 << '.' << ipip.ip4;
		}
		cout << ']' << endl;
	}
	if (ipb.size() != 0)
	{
		cout << "B:[";
		bool flag = true;
		for (auto &ipip : ipb)
		{
			if (flag == false)
			{
				cout << ',';
			}
			flag = false;
			cout << ipip.ip1 << '.' << ipip.ip2 << '.' << ipip.ip3 << '.' << ipip.ip4;
		}
		cout << ']' << endl;
	}
	if (ipc.size() != 0)
	{
		cout << "C:[";
		bool flag = true;
		for (auto &ipip : ipc)
		{
			if (flag == false)
			{
				cout << ',';
			}
			flag = false;
			cout << ipip.ip1 << '.' << ipip.ip2 << '.' << ipip.ip3 << '.' << ipip.ip4;
		}
		cout << ']' << endl;
	}
	if (ipd.size() != 0)
	{
		cout << "D:[";
		bool flag = true;
		for (auto &ipip : ipd)
		{
			if (flag == false)
			{
				cout << ',';
			}
			flag = false;
			cout << ipip.ip1 << '.' << ipip.ip2 << '.' << ipip.ip3 << '.' << ipip.ip4;
		}
		cout << ']' << endl;
	}
	if (ipe.size() != 0)
	{
		cout << "E:[";
		bool flag = true;
		for (auto &ipip : ipe)
		{
			if (flag == false)
			{
				cout << ',';
			}
			flag = false;
			cout << ipip.ip1 << '.' << ipip.ip2 << '.' << ipip.ip3 << '.' << ipip.ip4;
		}
		cout << ']' << endl;
	}
	return 0;
}