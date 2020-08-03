#include <bits/stdc++.h>
#define MAX_N 200 + 1
using namespace std;

int N, M;
int color[MAX_N];
vector<int> G[MAX_N];

bool dfs(int k, int change){
	int ans = true;

	if(color[k]){
		if(color[k] == change) return true;
		else return false;
	}
	else{
		color[k] = change;

		for(int &n : G[k])
			ans &= dfs(n, change ^ 3);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N){
		if(!N) break;
		else cin >> M;

		for(int i = 0; i <= 200; i++)
			G[i].clear();

		for(int i = 0; i < M; i++){
			int p, q;
			cin >> p >> q;
			G[p].push_back(q);
			G[q].push_back(p);
		}

		memset(color, 0, sizeof(color));

		if(dfs(0, 1)) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}

	return 0;
}