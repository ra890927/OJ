#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

struct Node{
	int v, cost;

	Node(){}
	Node(int v, int k) : v(v), cost(k){}

	bool operator < (const Node &other) const{
		return cost < other.cost;
	}
};

int N, S;
vector<int> G[MAX_N];

void Dijkstra(int t){
	int d[MAX_N] = {0};
	priority_queue<Node> pri_q;

	pri_q.push(Node(S, d[S]));

	while(!pri_q.empty()){
		Node p = pri_q.top();
		pri_q.pop();

		int u = p.v;
		if(p.cost < d[u]) continue;

		for(int &e : G[u]){
			if(d[e] < d[u] + 1){
				d[e] = d[u] + 1;
				pri_q.push(Node(e, d[e]));
			}
		}
	}

	int dis = 0, k = 0;
	for(int i = 1; i <= N; i++){
		if(d[i] > dis){
			k = i;
			dis = d[i];
		}
	}

	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t, S, dis, k);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, t, count = 1;;
	while(cin >> N){
		if(!N) break;
		
		for(int i = 0; i <= N; i++)
			G[i].clear();

		cin >> S;
		while(cin >> s >> t){
			if(!s && !t) break;
			G[s].push_back(t);
		}

		Dijkstra(count++);
	}

	return 0;
}