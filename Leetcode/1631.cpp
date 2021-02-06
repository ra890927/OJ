using Triplet = tuple<int, int, int>;
vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int minimumEffortPath(vector<vector<int>>& heights){
	const int row = heights.size();
	const int col = heights[0].size();
	vector<vector<int>> d(row, vector<int>(col, INT_MAX));
	priority_queue<Triplet, vector<Triplet>, greater<Triplet>> pri_q;

	d[0][0] = 0;
	pri_q.push({0, 0, 0});

	while(!pri_q.empty()){
		auto [x, y, k] = pri_q.top();
		pri_q.pop();

		for(const auto& [dx, dy] : dirs){
			if(x + dx < 0 || x + dx >= row || y + dy < 0 || y + dy >= col)
				continue;
			int w = max(k, abs(heights[x][y] - heights[x + dx][y + dy]));

			if(w < d[x + dx][y + dy]){
				d[x + dx][y + dy] = w;
				pri_q.push({x + dx, y + dy, w});
			}
		}
	}

	return d[row - 1][col - 1];
}