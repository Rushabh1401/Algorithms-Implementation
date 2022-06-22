#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back

int N = 1e5;
vector<int>intime(N, 0);
vector<int>outtime(N, 0);

void dfs(int node, int par, vector<vector<int>>&adj, int &currtime)
{
	intime[node] = currtime++;

	for (auto child : adj[node])
	{
		if (child == par)
			continue;

		dfs(child, node, adj, currtime);
	}

	outtime[node] = currtime++;
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
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int currtime = 0;

	dfs(1, 0, adj, currtime);

	for (int i = 1 ; i <= n ; i++)
	{
		cout << i << " intime: " << intime[i] << ", outtime: " << outtime[i] << endl;
	}
}
