#include <iostream>
#include <cstring>
#define MAXN 350 + 1
using namespace std;

int main(){
	int N;
	int dp[MAXN][MAXN];
	while(cin >> N){
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= i; j++){
				cin >> dp[i][j];
			}
		}
		for(int i = N - 1; i >= 0; i--){
			for(int j = 0; j <= i; j++){
				dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
				cout << dp[i][j] <<endl; 
			}
		}
		cout << dp[0][0] <<endl;
	}
	return 0;
}
