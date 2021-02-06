int minimumDeviation(vector<int>& nums){
	int m = INT_MAX;
	int ans = INT_MAX;
	priority_queue<int> pri_q;

	for(int &n : nums){
		if(n & 1) n *= 2;
		m = min(m, n);
		pri_q.push(n);
	}

	while(true){
		int n = pri_q.top();
		pri_q.pop();

		ans = min(ans, n - m);
		if(n & 1) break;

		m = min(m, n / 2);
		pri_q.push(n / 2);
	}

	return ans;
}