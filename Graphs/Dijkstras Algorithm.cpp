vector<int> min_distance(vector<vector<pair<int, int>>>&adj, int n ) {

	vector<int>ans(n + 1, INT_MAX);

	priority_queue<pair<int, int>>pq;

	pq.push({0, 1});
	ans[1] = 0;

	while (!pq.empty())
	{
		int curr = pq.top().second;
		int dis = -1 * pq.top().first;
		pq.pop();

		if (ans[curr] < dis)
			continue;

		for (auto x : adj[curr])
		{
			if ( ans[x.first] > x.second + dis)
			{
				ans[x.first] = x.second + dis ;
				pq.push( { -1 * ans[x.first] , x.first } );
			}
		}
	}

	return ans;

}
