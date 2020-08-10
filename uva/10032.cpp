#include <bits/stdc++.h>
#define MAX_N 100 + 1
#define MAX_W 23000
using namespace std;

int N, W;
int arr[MAX_N];

void solve(){
	int64_t dp[MAX_W] = {0};

	dp[0] = 1;
	for(int i = 0; i < N; i++)
		for(int j = W / 2; j >= arr[i]; j--)
			dp[j] |= (dp[j - arr[i]] << 1);

	if(N & 1){
		for(int i = W / 2; i >= 0; i--){
			int64_t flag1 = (1ll << (N / 2));
			int64_t flag2 = (1ll << (N / 2 + 1));

			if((dp[i] & flag1) || (dp[i] & flag2)){
				printf("%d %d\n", i, W - i);
				return;
			}
		}
	}
	else{
		for(int i = W / 2; i >= 0; i--){
			int64_t flag = (1ll << (N / 2));

			if(dp[i] & flag){
				printf("%d %d\n", i, W - i);
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		W = 0;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			W += arr[i];
		}

		solve();

		if(T != 0) printf("\n");
	}

	return 0;
}