#include <bits/stdc++.h>
#define MAX_N 10000 + 1
using namespace std;

struct Edge{
	int from, to, cost;

	bool operator < (const Edge &other) const{
		return cost < other.cost;
	}
};

int N, M, A;
vector<Edge> ed;
int r[MAX_N];
int parent[MAX_N];

int find(int x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	if(r[x] > r[y]) parent[y] = x;
	else{
		if(r[x] == r[y]) r[y] += 1;
		parent[x] = y;
	}
}

void Kruskal(){
	int ans = 0;
	vector<int> V;

	memset(r, 0, sizeof(r));
	sort(ed.begin(), ed.end());
	for(int i = 0; i <= N; i++)
		parent[i] = i;

	for(Edge &e : ed){
		int p = find(e.from);
		int q = find(e.to);

		if(p != q){
			unite(p, q);
			V.push_back(e.cost);
		}
	}

	int i;
	for(i = 0; i < V.size(); i++){
		if(V[i] >= A) break;
		ans += V[i];
	}

	int count = 0;
	for(int i = 1; i <= N; i++)
		if(parent[i] == i) count += 1;
	count += V.size() - i;
	ans += count * A;

	printf("%d %d\n", ans, count);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++){
		ed.clear();
		cin >> N >> M >> A;
		for(int i = 0; i < M; i++){
			Edge e;
			cin >> e.from >> e.to >> e.cost;
			ed.push_back(e);
		}

		printf("Case #%d: ", t);
		Kruskal();
	}

	return 0;
}