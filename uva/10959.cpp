#include <bits/stdc++.h>
#define MAX_N 1000 + 1
#define INF 1e9
using namespace std;
typedef pair<int, int> Pair;

int N;
int dis[MAX_N];
vector<int> G[MAX_N];

void bfs(){
	queue<Pair> que;
	bool visit[MAX_N] = {0};
	fill(dis, dis + N, INF);

	que.push(Pair(0, 0));

	while(!que.empty()){
		Pair p = que.front();
		que.pop();

		dis[p.first] = min(dis[p.first], p.second);
		visit[p.first] = true;

		for(int &n : G[p.first])
			if(!visit[n]) que.push(Pair(n, p.second + 1));
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, M;
	cin >> T;

	while(T--){
		for(int i = 0; i < MAX_N; i++)
			G[i].clear();

		cin >> N >> M;

		for(int i = 0; i < M; i++){
			int p, q;
			cin >> p >> q;
			G[p].push_back(q);
			G[q].push_back(p);
		}

		bfs();

		for(int i = 1; i < N; i++)
			printf("%d\n", dis[i]);

		if(T) printf("\n");
	}

	return 0;
}