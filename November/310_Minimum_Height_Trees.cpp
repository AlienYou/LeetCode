vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	vector<int> res;
	if (n < 2)
		return {0};
	vector<int> degree(n, 0);
	vector<vector<int>> graph(n, vector<int>());
	for (vector<int>& edge: edges)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
		degree[edge[0]]++;
		degree[edge[1]]++;
	}
	queue<int> que;
	for (int i = 0; i < n; ++i)
	{
		if (degree[i] == 1)
			que.push(i);
	}
	
	int nodes = n;
	while (nodes > 2)
	{
		int size = que.size();
		nodes -= size;
		for (int i = 0; i < size; ++i)
		{
			int curNode = que.front();
			que.pop();
			for (int j = 0; j < graph[curNode].size(); ++j)
			{
				degree[graph[curNode][j]]--;
				if (degree[graph[curNode][j]] == 1)
					que.push(graph[curNode][j]);
			}
		}
	}
	while (!que.empty())
	{
		int curNode = que.front();
		que.pop();
		res.push_back(curNode);
	}
	return res;
}