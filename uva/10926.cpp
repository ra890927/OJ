#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

int N;
int dis[MAX_N];
vector<int> G[MAX_N];

int dfs(int s){
	if(dis[s]) return dis[s];

	int Max = 0;

	for(int &n : G[s])
		Max = max(Max, dfs(n) + 1);
	
	return dis[s] = Max;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N){
		if(!N) break;

		for(int i = 0; i <= N; i++)
			G[i].clear();

		int t, k;
		for(int i = 1; i <= N; i++){
			cin >> t;
			while(t--){
				cin >> k;
				G[i].push_back(k);
			}
		}

		memset(dis, 0, sizeof(dis));

		for(int i = 1; i <= N; i++)
			dfs(i);

		int ans = 1;
		for(int i = 2; i <= N; i++)
			if(dis[i] > dis[ans]) ans = i;

		printf("%d\n", ans);
	}

	return 0;
}