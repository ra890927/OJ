#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

struct Edge{
	int from, to, cost;

	bool operator < (const Edge &other) const{
		if(cost == other.cost){
			if(from == other.from)
				return to < other.to;
			return from < other.from;
		}
		return cost < other.cost;
	}
};

int N;
int r[MAX_N];
int parent[MAX_N];
vector<Edge> ed;

Edge make_edge(int from, int to, int cost){
	Edge e;
	e.from = from, e.to = to, e.cost = cost;
	return e;
}

int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	if(r[x] < r[y]) parent[x] = y;
	else if(r[x] > r[y]) parent[y] = x;
	else{
		parent[x] = y;
		r[x] += 1;
	}
}

void Kruskal(){
	memset(r, 0, sizeof(r));
	for(int i = 0; i < N; i++)
		parent[i] = i;

	sort(ed.begin(), ed.end());
	for(Edge &e : ed){
		int p = find(e.from);
		int q = find(e.to);

		if(p != q){
			unite(p, q);
			printf("%c-%c %d\n", e.from + 'A', e.to + 'A', e.cost);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, k;
	char c;
	cin >> T;

	for(int s = 1; s <= T; s++){
		cin >> N;
		ed.clear();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(j == N - 1) cin >> k;
				else cin >> k >> c;

				if(i < j && k) ed.push_back(make_edge(i, j, k));
			}
		}

		printf("Case %d:\n", s);
		Kruskal();
	}

	return 0;
}