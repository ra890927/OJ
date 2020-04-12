#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#define INF 1e9
#define origin 100000
using namespace std;

int N;
pair<int, int> a[101];

void solve(){
	int dp[200001];
	fill(dp, dp + 200001, -INF);
	dp[origin] = 0;
	
	for(int i = 0; i < N; i++){
		if(a[i].first >= 0){
			for(int j = 100000; j >= -100000; j--)
				if(j - a[i].first + origin >= 0)
					dp[j + origin] = max(dp[j + origin], dp[j + origin - a[i].first] + a[i].second);
		}
		else{
			for(int j = -100000; j <= 100000; j++)
				if(j - a[i].first + origin <= 200000)
					dp[j + origin] = max(dp[j + origin], dp[j + origin - a[i].first] + a[i].second);
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= 100000; i++)
		if(dp[i + origin] >= 0)
			ans = max(ans, dp[i + origin] + i);
		
	cout << ans << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i].first >> a[i].second;
	
	solve();
	
	return 0;
}