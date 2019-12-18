#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 1000 + 1
#define INF 1E9
using namespace std;

struct edge{
	int to, cost;
};

struct node{
	int v, k;
	bool operator > (const node &other) const{
		return k > other.k;
	}
};

edge make_edge(int to, int cost){
	edge e;
	e.to = to, e.cost = cost;
	return e;
}

node make_node(int v, int k){
	node n;
	n.v = v, n.k = k;
	return n;
}

int V, E, T;
int dis[MAX_V];
vector<edge> ed[MAX_V];

int Dijkstra(int start, int end){
	int d[MAX_V];
	priority_queue<node, vector<node>, greater<node>> pri_q;
	fill(d, d + V + 1, INF);
	
	d[start] = 0;
	pri_q.push(make_node(start, d[start]));
	
	while(!pri_q.empty()){
		node p = pri_q.top();
		pri_q.pop();
		
		int u = p.v;
		if(d[u] < p.k) continue;
		
		for(int i = 0; i < ed[u].size(); i++){
			edge e = ed[u][i];
			if(d[e.to] > d[u] + e.cost){
				d[e.to] = d[u] + e.cost;
				pri_q.push(make_node(e.to, d[e.to]));
			}
		}
	}
	
	if(end) return d[end];
	else{
		for(int i = 1; i <= V; i++)
			dis[i] += d[i];
		
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> V >> E >> T;
	for(int i = 0; i < E; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		ed[from].push_back(make_edge(to, cost));
	}
	
	int ans = Dijkstra(T, 0);
	for(int i = 1; i <= V; i++){
		dis[i] += Dijkstra(i, T);
		ans = max(ans, dis[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}