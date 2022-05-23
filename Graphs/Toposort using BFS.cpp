#include <bits/stdc++.h>
using namespace std;

// Necessary Condition for Toposort
//No cycle
//Directed Graph

void toposort(vector<vector<int>>&adj)
{
    int n = adj.size();
    vector<int>indegree(n,0);

    for(auto x : adj)
    {
        for(auto y : x)
        indegree[y]++;
    }

    queue<int>q;
    vector<int>ans;

    for(int i=0 ; i<n ; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }

    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto x : adj[curr])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
                ans.push_back(x);
            }
            
        }
    }

    for(auto x: ans)
    cout<<x<<" ";
}

int main() {
    vector<vector<int>>adj = {{},{},{3},{1},{0,1},{0,2}};
    toposort(adj);
}
