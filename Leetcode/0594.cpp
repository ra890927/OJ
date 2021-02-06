int findLHS(vector<int>& nums){
	unordered_map<int, int> umap;
	for(int &n : nums)
		umap[n] += 1;

	int ans = 0;
	for(auto [n, f] : umap){
		if(umap.find(n + 1) != umap.end())
			ans = max(ans, f + umap[n + 1]);
	}

	return ans;
}