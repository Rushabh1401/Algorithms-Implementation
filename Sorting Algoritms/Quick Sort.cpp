#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

// TC : In worst cast -> T(N) = T(N-1)+n; // O(N^2) // Pivot ele is last
// TC : In best case -> T(N) = 2T(N/2)+n; //O(NlogN); //Pivot ele is median

int partition(vector<int>&arr, int l, int r)
{
	//considering pivot as last element everytime
	int pivot_ele = arr[r];

	int i = l - 1;
	int j = l;

	//i -> last index of smaller elements than pivot
	//j -> element index greater than or equal to pivot

	while (j < r)
	{
		if (arr[j] < pivot_ele)
		{
			i++;
			swap(arr[i], arr[j]);
		}

		j++;
	}

	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void QuickSort(vector<int>&arr, int l, int r)
{
	if (l >= r)
		return;

	int pivot = partition(arr, l, r);

	QuickSort(arr, l, pivot - 1);
	QuickSort(arr, pivot + 1, r);
}

int main()
{
	int n;
	cin >> n;

	vector<int>arr(n);

	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	QuickSort(arr, 0, n - 1);

	for (int i = 0 ; i < n ; i++)
		cout << arr[i] << " ";
}
