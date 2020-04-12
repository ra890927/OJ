#include <iostream>
#include <cstring>
#define MAX_N 1000 + 1
#define MAX_W 30 + 1
using namespace std;

int N, W;
int dp[MAX_W];
int tree[MAX_N];

void solve(){
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1 -  tree[0], dp[1] = tree[0];
	
	for(int i = 1; i < N; i++){
		dp[0] = dp[0] + 1 - tree[i];
		for(int j = W; j > 0; j--)
			dp[j] = max(dp[j - 1], dp[j]) + !(tree[i] ^ (j % 2));
	}
	
	for(int i = 0; i <= W; i++)
		ans = max(ans, dp[i]);
	
	cout << ans << endl;
}

int main(){
	cin >> N >> W;
	for(int i = 0; i < N; i++){
		cin >> tree[i];
		tree[i]--;
	}
	
	solve();
	
	return 0;
}