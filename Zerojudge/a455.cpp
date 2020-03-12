#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;

bool cmp(int a, int b){
	return a > b;
}
char p[1000][3000];
int main(){
	int M, N;
	while(cin>>M>>N){
		int ans = 0;
		int b[50], w[1000];
		bool used[1000];
		for(int i = 0; i < M; i++)
			cin>>b[i];
		for(int i = 0; i < N; i++)
			cin>>w[i];
		sort(b, b + M);
		sort(w, w + N, cmp);
		for(int i = 0; i < M; i++){
			int dp[3000] = {};
			memset(p, 0, sizeof(p)); 
			for(int j = 0; j < N; j++){
				if(!used[j]){
					for(int k = b[i]; k >= 0; k--){
						if(k-w[j] >= 0 && dp[k-w[j]]+1 > dp[k]){
							dp[k] = dp[k-w[j]]+1;
							p[j][k]=1;
						}
					}
				}
			}
			if(!dp[b[i]]) break;
			ans += dp[b[i]];
			for(int j = N - 1, k = b[i]; j >= 0; j--){
				if(p[j][k]){
					used[j] = true;
					k -= w[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}