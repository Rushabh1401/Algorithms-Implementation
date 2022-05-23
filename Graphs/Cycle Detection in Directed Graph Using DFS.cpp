#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int curr,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsvis)
{
    vis[curr] = 1;
    dfsvis[curr] = 1;

    for(auto x: adj[curr])
    {
        if(!vis[x])
        {
            dfsCycle(x,adj,vis,dfsvis);
        }

        else if(dfsvis[x] == 1)
        return true;

    }

    dfsvis[curr] = 0;
    return false;
}

bool detectCycle(vector<vector<int>>&adj)
{
    int n = adj.size();
    vector<int>vis(n,0);
    vector<int>dfsvis(n,0);

    for(int i=0 ; i<n ; i++)
    {
        if(dfsCycle(i,adj,vis,dfsvis))
        return true;
    }

    return false;   
}

int main() {
    vector<vector<int>>adj = {{1},{2},{3},{4},{5},{0}};
    cout<<detectCycle(adj);
}
