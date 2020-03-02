#include <iostream>
#define MAX_N 1000000 + 1
using namespace std;

int N, dp[MAX_N] = {0};
const int mod = 1e9;

int main(){
	dp[1] = 1, dp[2] = 2;
	
	for(int i = 3; i < MAX_N; i++){
		if(i & 1) dp[i] = dp[i - 1];
		else dp[i] = dp[i - 2] + dp[i / 2];
		dp[i] %= mod;
	}
	
	while(cin >> N)
		cout << dp[N] << endl;
	
	return 0;
}