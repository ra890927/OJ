bool isPalindrome(ListNode* head){
	vector<int> v;
	for(auto it = head; it != NULL; it = it->next)
		v.push_back(it->val);

	for(int i = 0; i < v.size() / 2; i++)
		if(v[i] != v[v.size() - i - 1]) return false;

	return true;
}