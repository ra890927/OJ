#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 5000 + 1
using namespace std;

int N;
struct Wood{
	int w, l;
	bool operator < (const Wood& other) const{
		return l < other.l;
	}
}wood[MAXN];
bool dp[MAXN];

void solve(){
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		if(!dp[i]){
			int last = wood[i].w;
			dp[i] = true;
			ans++;
			for(int j = i + 1; j < N; j++){
				if(wood[j].w >= last && !dp[j]){
					last = wood[j].w;
					dp[j] = true;
				}
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		memset(wood, 0, sizeof(wood));
		for(int i = 0; i < N; i++)
			cin >> wood[i].l >> wood[i].w;
		sort(wood, wood + N);
		solve();
	}
	return 0;
}
