#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&depth, vector<int>&height)
{

	for (auto child : adj[node])
	{
		if (child == parent)
			continue;

		depth[child] = depth[node] + 1;
		dfs(child, node, adj, depth, height);
		height[node] = max(height[node], height[child] + 1);
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>>adj(n + 1);

	for (int i = 1 ; i <= n - 1 ; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int>depth(n + 1, 0);
	vector<int>height(n + 1, 0);


	dfs(1, 0, adj, depth, height);

	for (int i = 1 ; i <= n ; i++)
		cout << depth[i] << " " << height[i] << endl;
}
