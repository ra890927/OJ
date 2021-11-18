int findMaxForm(vector<string>& strs, int m, int n){
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(string &str : strs){
		int one = 0, zero = 0;
		for(char &c : str)
			(c == '1') ? one += 1 : zero += 1;
		for(int i = m; i >= zero; i--)
			for(int j = n; j >= one; j--)
				dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
	}

	return dp[m][n];
}