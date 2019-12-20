#include <bits/stdc++.h>
#define MAX_V 10000 + 1
#define INF 1E9
using namespace std;

struct edge{
	int to, dis, cost;
	bool operator > (const edge &other) const{
		if(dis == other.dis) return cost > other.cost;
		return dis > other.dis;
	}
};

edge make_edge(int to, int dis, int cost){
	edge e;
	e.to = to, e.dis = dis, e.cost = cost;
	return e;
}

int V, E;
vector<edge> G[MAX_V];

int Dijkstra(){
	int sum = 0;
	bool visit[MAX_V];
	priority_queue<edge, vector<edge>, greater<edge>> pri_q;
	
	memset(visit, 0, sizeof(visit));
	pri_q.push(make_edge(1, 0, 0));
		
	while(!pri_q.empty()){
		edge p = pri_q.top();
		pri_q.pop();
		
		int u = p.to;
		if(visit[u]) continue;
		visit[u] = true;
		sum += p.cost;
		
		for(int i = 0; i < G[u].size(); i++){
			edge e = G[u][i];
			pri_q.push(make_edge(e.to, p.dis + e.dis, e.cost));
		}
	}
		
	return sum;
}

int main(){
	while(cin >> V >> E){
		if(!V && !E) break;
		
		for(int i = 0; i < E; i++){
			int from, to, dis, cost;
			cin >> from >> to >> dis >> cost;
			G[from].push_back(make_edge(to, dis, cost));
			G[to].push_back(make_edge(from, dis, cost));
		}
		
		cout << Dijkstra() << endl;
		
		for(int i = 0; i <= V; i++)
			G[i].clear();
	}
	
	return 0;
}