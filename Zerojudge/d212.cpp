#include <iostream>
using namespace std;

int main(){
	int k;
	long long int dp[100];
	dp[1] = 1, dp[2] = 2;
	for(int i = 3; i < 100; i++)
		dp[i] = dp[i-1] + dp[i-2];
	while(cin >> k)
		cout << dp[k] << endl;
	return 0;
}