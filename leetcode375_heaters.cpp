#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
	// code here
	int ans = 0;
	sort(heaters.begin(), heaters.end());
	for (auto h : houses)
	{
		auto ite = lower_bound(heaters.begin(), heaters.end(), h);
		int leftdis = 0;
		int rightdis = 0;
		if (ite == heaters.begin())
		{
			leftdis = INT_MAX;
			rightdis = *ite - h;
		}
		else if (ite == heaters.end())
		{
			leftdis =abs(*(--ite) - h);
			rightdis = INT_MAX;
		}
		else
		{
			rightdis = abs(*ite - h);
			leftdis = abs(*(--ite) - h);
		}
		int temp = min(leftdis, rightdis);
		ans = max(temp, ans);
	}
	return ans;
}

int main() {
	int M, N;
	cin >> M >> N;
	vector<int> houses, heaters;
	while (M--) {
		int p;
		cin >> p;
		houses.push_back(p);
	}

	while (N--) {
		int p;
		cin >> p;
		heaters.push_back(p);
	}

	cout << findRadius(houses, heaters) << endl;
	system("pause");
}
