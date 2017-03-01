#include<iostream>
#include<cstdio>
using namespace std;

void quicksort(int a[], int start, int end);
int main()
{
	int a[1000];
	srand(111);
	for (int x = 0; x < 200; x++)
	{
		a[x] = rand() % 100;
		cout << a[x] << " ";
	}
	cout << endl;
	quicksort(a,0,199);
	for (const auto x : a) cout << x << " ";
	int kkk;
	cin >> kkk;
	return 0;
}

void quicksort(int a[], int start, int end)
{
	if (start >= end) return;
	int x = a[start];
	int l = start, r = end;
	while (l < r)
	{
		while (l < r && a[r] > x) --r;	
		if (l < r) a[l++] = a[r];
		while (l < r && a[l] < x) ++l;	
		if (l < r) a[r--] = a[l];
	}
	a[l] = x;
	quicksort(a, start, l - 1);
	quicksort(a, l + 1, end);
}