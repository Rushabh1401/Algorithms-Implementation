#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back

void dfs(int node, int par, vector<vector<int>>&adj, vector<int>&depth, vector<vector<int>>&powof2_parent)
{
	powof2_parent[node][0] = par;

	for (auto child : adj[node])
	{
		if (child == par)
			continue;
		//Calculating depth for child using parent
		depth[child] = depth[node] + 1;
		dfs(child, node, adj, depth, powof2_parent);
	}
}

void find_all_powof2_parents(vector<vector<int>>&powof2_parent, int limit, int n)
{
	for (int i = 1 ; i <= limit ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			//4th parent of node is node ka 2nd parent's 2nd parent.
			int intermediate = powof2_parent[j][i - 1];

			if (intermediate != -1)
				powof2_parent[j][i] = powof2_parent[intermediate][i - 1];
		}
	}
}

int find_k_parent(vector<vector<int>>&powof2_parent, int node, int k)
{
	int k_par = node;

	for (int i = 0 ; i <= log2(k) ; i++)
	{
		if ((1 << i)&k)
			k_par = powof2_parent[k_par][i];

		if (k_par == -1)
			break;
	}

	return k_par;
}

int lcs(vector<int>&depth, vector<vector<int>>&powof2_parent, int a, int b, int limit)
{
	if (depth[a] > depth[b])
		swap(a, b);

	int diff = depth[b] - depth[a];

	b = find_k_parent(powof2_parent, b, diff);

	if (a == b)
		return a;

	for (int i = limit ; i >= 0 ; i--)
	{
		if (powof2_parent[a][i] == -1 || powof2_parent[a][i] == powof2_parent[b][i])
			continue;

		a = powof2_parent[a][i];
		b = powof2_parent[b][i];
	}

	return powof2_parent[a][0];
}


int main()
{
	int n;
	cin >> n ;

	vector<vector<int>>adj(n + 1);

	for (int i = 1 ; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	//staring from 1 till n
	vector<int>depth(n + 1);

	//Taking 1,2,4,8,16....log2(n) and +2 for safety.
	int limit = log2(n) + 2;

	//all parents initially stored to 0;
	vector<vector<int>>powof2_parent(n + 1, vector<int>(limit + 1, -1));

	//running dfs to caluclate depth and first parent which is stored in 0th column
	dfs(1, -1, adj, depth, powof2_parent);

	//precomputation in O(nlogn)
	find_all_powof2_parents(powof2_parent, limit, n);

	//finding kth parent in O( log2(k) )
	cout << find_k_parent(powof2_parent, 1, 3) << endl;

	//finding lcs in O(log n) using precomputation
	cout << lcs(depth, powof2_parent, 5, 4 , limit) << endl;

	int i = 0;

	for (auto x : powof2_parent)
	{
		cout << i << " parent list : ";
		for (auto y : x)
			cout << y << " ";

		i++;
		cout << endl;
	}
}
