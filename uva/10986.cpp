#include <bits/stdc++.h>
#define MAX_N 20000 + 1
using namespace std;

struct Node{
	int v, cost;

	Node(){}
	Node(int v, int k) : v(v), cost(k){}

	bool operator < (const Node &other) const{
		return cost > other.cost;
	}
};

int N, M, S, E;
vector<Node> G[MAX_N];

void Dijkstra(int t){
	int d[MAX_N];
	priority_queue<Node> pri_q;

	fill(d, d + N + 1, INT_MAX);
	d[S] = 0;
	pri_q.push(Node(S, d[S]));

	while(!pri_q.empty()){
		Node p = pri_q.top();
		pri_q.pop();

		int u = p.v;
		if(p.cost > d[u]) continue;

		for(Node &e : G[u]){
			if(d[e.v] > d[u] + e.cost){
				d[e.v] = d[u] + e.cost;
				pri_q.push(Node(e.v, d[e.v]));
			}
		}
	}

	if(d[E] == INT_MAX) printf("Case #%d: unreachable\n", t);
	else printf("Case #%d: %d\n", t, d[E]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++){
		int from, to, cost;
		cin >> N >> M >> S >> E;

		for(int i = 0; i <= N; i++)
			G[i].clear();

		for(int i = 0; i < M; i++){
			cin >> from >> to >> cost;
			G[from].push_back(Node(to, cost));
			G[to].push_back(Node(from, cost));
		}

		Dijkstra(t);
	}

	return 0;
}