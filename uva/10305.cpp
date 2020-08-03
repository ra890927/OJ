#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

int N, M;
int E[MAX_N];
vector<int> G[MAX_N], ans;

void init(){
	ans.clear();
	memset(E, 0, sizeof(E));

	for(int i = 0; i < MAX_N; i++)
		G[i].clear();
}

void Topological_sort(){
	for(int i = 1; i <= N; i++){
		int j;
		for(j = 1; j <= N; j++)
			if(!E[j] && E[j] != -1) break;

		E[j] = -1;
		ans.push_back(j);

		for(int &n : G[j])
			E[n] -= 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N >> M){
		if(N + M == 0) break;

		init();

		int p, q;
		for(int i = 0; i < M; i++){
			cin >> p >> q;
			G[p].push_back(q);
			E[q] += 1;
		}

		Topological_sort();

		for(int i = 0; i < ans.size() - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[ans.size() - 1]);
	}

	return 0;
}