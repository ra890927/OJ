#include <iostream>
#define MAX_N 10000 + 1
using namespace std;

int N;
int v[MAX_N], w[MAX_N], dp[101];

void solve(){
	for(int i = 0; i < N; i++)
		for(int j = 100; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
	cout << dp[100] << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> w[i] >> v[i];
	solve();
	return 0;
}