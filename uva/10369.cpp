#include <bits/stdc++.h>
#define MAX_V 500 + 1
using namespace std;
typedef pair<int, int> Node;

struct Edge{
	int to;
	double cost;

	bool operator > (const Edge &other) const{
		return cost > other.cost;
	}
};

int S, V;
Node arr[MAX_V];

double get_cost(int x, int y){
	return sqrt((arr[x].first - arr[y].first) * (arr[x].first - arr[y].first) + (arr[x].second - arr[y].second) * (arr[x].second - arr[y].second));
}

Edge make_edge(int v, double cost){
	Edge e;
	e.to = v, e.cost = cost;
	return e;
}

void Prim(){
	vector<Edge> ed[MAX_V];
	bool visit[MAX_V] = {0};
	priority_queue<Edge, vector<Edge>, greater<Edge>> pri_q;

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			if(i != j) ed[i].push_back(make_edge(j, get_cost(i, j)));

	pri_q.push(make_edge(0, 0));
	priority_queue<double> route;

	while(!pri_q.empty()){
		Edge p = pri_q.top();
		pri_q.pop();

		int u = p.to;
		if(visit[u]) continue;
		visit[u] = true;
		route.push(p.cost);

		for(Edge &e : ed[u])
			if(!visit[e.to]) pri_q.push(e);
	}

	while(S--) route.pop();

	printf("%.2lf\n", route.top());
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		cin >> S >> V;
		for(int i = 0; i < V; i++)
			cin >> arr[i].first >> arr[i].second;
		S -= 1;

		Prim();
	}

	return 0;
}