#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_N 1000 + 1
#define MAX_P 10000 + 2
#define INF 1E9
using namespace std;

struct Cabble{
	int a, b, L;
	bool operator < (const Cabble &other) const{
		return L < other.L;
	}
};

struct Edge{
	int to, cost;
};

struct Node{
	int v, dis;
	bool operator > (const Node &other) const{
		return dis > other.dis;
	}
};

int N, P, K;
int d[MAX_N];
Cabble cab[MAX_P];
vector<Edge> ed[MAX_N];

Node make_node(int v, int dis){
	Node ret;
	ret.v = v;
	ret.dis = dis;
	return ret;
}

bool C(int x){
	priority_queue<Node, vector<Node>, greater<Node>> pri_q;
	fill(d, d + N + 1, INF);
	
	d[1] = 0;
	pri_q.push(make_node(1, d[1]));
	
	while(!pri_q.empty()){
		Node p = pri_q.top();
		pri_q.pop();
		
		int u = p.v;
		if(d[u] < p.dis) continue;
		for(int i = 0; i < ed[u].size(); i++){
			Edge e = ed[u][i];
			int cost = d[u] + (x < e.cost);
			if(d[e.to] > cost){
				d[e.to] = cost;
				pri_q.push(make_node(e.to, d[e.to]));
			}
		}
	}
	
	return d[N] <= K;
}

Edge make_edge(int to, int cost){
	Edge edge;
	edge.to = to;
	edge.cost = cost;
	return edge;
}

void add_edge(int from, int to, int cost){
	ed[from].push_back(make_edge(to, cost));
	ed[to].push_back(make_edge(from, cost));
}

void solve(){
	sort(cab, cab + P + 1);
	
	cab[0].L = 0;
	cab[P + 1].L = -1;
	
	int ub = P + 1, lb = -1, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(C(cab[mid].L)) ub = mid;
		else lb = mid;
	}
	
	cout << cab[ub].L << endl;
}

int main(){
	cin >> N >> P >> K;
	for(int i = 1; i <= P; i++){
		cin >> cab[i].a >> cab[i].b >> cab[i].L;
		add_edge(cab[i].a, cab[i].b, cab[i].L);
	}
	solve();
	return 0;
}