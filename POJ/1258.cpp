#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_V 100 + 1
#define INF 1E9
using namespace std;
typedef long long ll;

struct edge{
	int to;
	ll cost;
	bool operator < (const edge &other) const{
		return other.cost < cost;
	}
};

edge make_edge(int to, ll cost){
	edge e;
	e.to = to, e.cost = cost;
	return e;
}

int V;
int G[MAX_V][MAX_V];

ll Prim(){
	ll sum = 0;
	bool visit[MAX_V];
	priority_queue<edge> pri_q;
	
	memset(visit, 0, sizeof(visit));
	visit[1] = true;
	for(int i = 2; i <= V; i++)
		pri_q.push(make_edge(i, G[1][i]));
	
	while(!pri_q.empty()){
		edge p = pri_q.top();
		pri_q.pop();
			
		int u = p.to;
		if(visit[u]) continue;
		visit[u] = true;
		sum += p.cost;
		
		for(int i = 1; i <= V; i++)
			if(i != u)
				pri_q.push(make_edge(i, G[u][i]));
	}
	
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while(cin >> V){
		memset(G, 0, sizeof(G));
		
		for(int i = 1; i <= V; i++)
			for(int j = 1; j <= V; j++)
				cin >> G[i][j];
		
		cout << Prim() << endl;
	}
	
	return 0;
}