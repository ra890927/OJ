#include <iostream>
#include <algorithm>
#define MAX_N 40000 + 1
#define INF 1e9
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k, T, N, dp[MAX_N];
	
	cin >> T;
	while(T--){
		cin >> N;
		fill(dp, dp + N, INF);
		
		for(int i = 0; i < N; i++){
			cin >> k;
			*lower_bound(dp, dp + N, k) = k;
		}
		
		cout << lower_bound(dp, dp + N, INF) - dp << endl;
	}
	
	return 0;
}