#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

int64_t dp[MAX_N][MAX_N];

void solve(){
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < MAX_N; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	int N, M;
	while(cin >> N >> M){
		if(N + M == 0) break;
		printf("%d things taken %d at a time is %ld exactly.\n", N, M, dp[N][M]);
	}

	return 0;
}