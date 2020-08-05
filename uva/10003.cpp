#include <bits/stdc++.h>
#define MAX_N 50 + 5
#define INF 1e9
using namespace std;

int L, N;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

void solve(){
	for(int i = 0; i < N + 2; i++){
		for(int j = 0; j < N + 2; j++)
			dp[i][j] = INF;
		dp[i][i + 1] = 0;
	}

	for(int k = 2; k < N + 2; k++){
		for(int i = 0; i + k < N + 2; i++){
			int j = i + k;
			for(int m = i + 1; m < j; m++)
				dp[i][j] = min(dp[i][j], dp[i][m] + dp[m][j] + arr[j] - arr[i]);
		}
	}

	printf("The minimum cutting is %d.\n", dp[0][N + 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> L){
		if(!L) break;

		cin >> N;
		arr[0] = 0, arr[N + 1] = L;
		for(int i = 1; i <= N; i++)
			cin >> arr[i];

		solve();
	}

	return 0;
}