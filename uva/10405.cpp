#include <iostream>
#include <cstring>
#define MAX_N 1000 + 5
using namespace std;

string a, b;
int dp[MAX_N][MAX_N];

void LCS(){
	memset(dp, 0, sizeof(dp));
	int N = a.length(), M = b.length();

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	cout << dp[N][M] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(getline(cin, a)){
		getline(cin, b);
		LCS();
	}
	
	return 0;
}