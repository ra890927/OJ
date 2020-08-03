#include <bits/stdc++.h>
#define MAX_N 1000 + 1
using namespace std;

int N;
int v[MAX_N], w[MAX_N];
int dp[MAX_N];

void solve(){
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < N; i++)
		for(int j = 30; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, M, k;
	cin >> T;

	while(T--){
		cin >> N;

		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));

		for(int i = 0; i < N; i++)
			cin >> v[i] >> w[i];

		int ans = 0;
		solve();
		cin >> M;

		while(M--){
			cin >> k;
			ans += dp[k];
		}

		printf("%d\n", ans);
	}

	return 0;
}