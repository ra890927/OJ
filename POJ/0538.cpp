TreeNode* convertBST(TreeNode* root){
	if(!root) return NULL;

	int new_val = 0;
	queue<TreeNode*> que;
	unorder(que, root);

	while(!que.empty()){
		TreeNode *current = que.front();
		que.pop();

		current->val += new_val;
		new_val = current->val;
	}

	return root;
}

void unorder(queue<TreeNode*>& que, TreeNode *current){
	if(current->right) unorder(que, current->right);
	que.push(current);
	if(current->left) unorder(que, current->left);
}