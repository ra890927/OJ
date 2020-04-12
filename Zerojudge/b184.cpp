#include <bits/stdc++.h>
#define MAXN 1000 + 1
using namespace std;

int N;
int w[MAXN], v[MAXN], dp[101];

void solve(){
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		for(int j = 100; j >= 0; j--){
			if(j - w[i] >= 0)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			ans = max(ans, dp[j]);
		}
	}
	cout << ans << endl;
}

int main(){
	while(cin >> N){
		memset(w, 0, sizeof(w));
		memset(v, 0, sizeof(v));
		for(int i = 0; i < N; i++)
			scanf("%d %d", &w[i], &v[i]);
		solve();
	}
	return 0;
}
