vector<vector<int>> verticalTraversal(TreeNode* root){
	vector<vector<int>> vec;
	map<int, vector<int>> mmap;
	queue<pair<TreeNode*, pair<int, int>>> que;

	que.push({root, {0, 0}});
	while(!que.empty()){
		int size = que.size();
		unordered_map<int, vector<int>> umap;

		for(int i = 0; i < size; i++){
			auto p = que.front();
			que.pop();

			int x = p.second.first;
			int y = p.second.second;
			TreeNode* node = p.first;
			umap[y].push_back(node->val);

			if(node->left) que.push({node->left, {x + 1, y - 1}});
			if(node->right) que.push({node->right, {x + 1, y + 1}});
		}

		for(auto it = umap.begin(); it != umap.end(); it++){
			auto v = it->second;
			sort(v.begin(), v.end());
			for(auto n : v)
				mmap[it->first].push_back(n);
		}
	}

	for(auto it = mmap.begin(); it != mmap.end(); it++){
		auto v = it->second;
		vec.push_back(v);
	}

	return vec;
}