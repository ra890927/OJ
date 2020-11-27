#include <bits/stdc++.h>
#define MAX_N 200000 + 1
using namespace std;

int64_t N;
int64_t cnt[MAX_N];
bool visit[MAX_N];
vector<int> G[MAX_N];
queue<int> que;

void init(int N){
	memset(cnt, 0, sizeof(cnt));
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i <= N; i++)
		G[i].clear();
}

int64_t dfs(int u, int fa){
	int64_t res = 1;
	for(int &n : G[u]){
		if(n == fa || !visit[n]) continue;
		res += dfs(n, u);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		init(N);
		for(int i = 0; i < N; i++){
			int from, to;
			cin >> from >> to;
			G[from].push_back(to);
			G[to].push_back(from);
			cnt[from] += 1;
			cnt[to] += 1;
		}

		for(int i = 1; i <= N; i++)
			if(cnt[i] == 1) que.push(i);

		while(!que.empty()){
			int v = que.front();
			que.pop();
			visit[v] = true;

			for(int &k : G[v]){
				cnt[k] -= 1;
				if(cnt[k] == 1) que.push(k);
			}
		}

		int64_t ans = N * (N - 1);
		for(int i = 1; i <= N; i++){
			if(!visit[i]){
				int64_t temp = dfs(i, i);
				ans -= temp * (temp - 1) / 2;
			}
		}
		cout << ans << endl;
	}

	return 0;
}