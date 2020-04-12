#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int M,N,P;
	while(cin>>M>>N>>P){
		int W,V;
		int dp[51][10001];
		for(int i=1;i<=N;i++){
			for(int k=0;k<=M;k++)
				dp[i][k]=max(dp[i][k],dp[i-1][k]);
			for(int j=1;j<=P;j++){
				scanf("%d %d",&W,&V);
				for(int k=0;k<=M-W;k++){
					dp[i][W+k]=max(dp[i][W+k],dp[i-1][k]+V);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=M;i++)
			ans=max(ans,dp[N][i]);
		cout<<ans<<endl;
	}
}