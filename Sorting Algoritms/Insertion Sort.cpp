#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void InsertionSort(vector<int>&arr) {

	int n  = arr.size();

	for (int i = 1 ; i < n ; i++) {

		int curr = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > curr) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = curr;
	}
}

int main()
{
	vector<int>arr = {5, 3, 8, 9, 0};

	InsertionSort(arr);

	for (int i = 0 ; i < 5 ; i++)
		cout << arr[i] << " ";

}
