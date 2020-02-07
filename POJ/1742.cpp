#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100 + 1
#define MAX_M 100000 + 1
using namespace std;

int N, M;
int v[MAX_N], w[MAX_N];

void solve(){
	int dp[MAX_M];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= M; j++){
			if(dp[j] >= 0) dp[j] = w[i];
			else if(j < v[i] || dp[j - v[i]] <= 0) dp[j] = -1;
			else dp[j] = dp[j - v[i]] - 1;
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= M; i++)
		if(dp[i] >= 0) cnt++;

	cout << cnt << endl;
}

int main(){
	while(cin >> N >> M){
		if(!N && !M) break;
		
		for(int i = 0; i < N; i++)
			cin >> v[i];
		for(int i = 0; i < N; i++)
			cin >> w[i];
		
		solve();
	}
	
	return 0;
}