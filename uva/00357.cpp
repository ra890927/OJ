#include <bits/stdc++.h>
#define MAX_N 30000 + 1
using namespace std;

int64_t dp[MAX_N];
const int64_t money[] = {1, 5, 10, 25, 50};

void solve(){
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = money[i]; j < MAX_N; j++)
			dp[j] += dp[j - money[i]];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	int N;
	while(cin >> N){
		if(dp[N] == 1) printf("There is only 1 way to produce %d cents change.\n", N);
		else printf("There are %ld ways to produce %d cents change.\n", dp[N], N);
	}

	return 0;
}