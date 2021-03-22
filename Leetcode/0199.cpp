vector<int> rightSideView(TreeNode* root){
	vector<int> v;
	queue<TreeNode*> que;

	if(!root) return v;

	que.push(root);
	while(!que.empty()){
		TreeNode *current;
		int size = que.size();

		while(size--){
			current = que.front();
			que.pop();

			if(current->left) que.push(current->left);
			if(current->right) que.push(current->right);
		}

		v.push_back(current->val);
	}

	return v;
}