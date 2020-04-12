#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_N 1000 + 1
using namespace std;
typedef long long ll;

struct edge{
	int to, cost;
	
	bool operator < (const edge &other) const{
		return cost < other.cost;
	}
};

edge make_edge(int to, int cost){
	edge e;
	e.to = to, e.cost = cost;
	return e;
}

int V, N;
vector<edge> G[MAX_N];

void add_edge(int from, int to, int cost){
	G[from].push_back(make_edge(to, cost));
	G[to].push_back(make_edge(from, cost));
}

int Prim(){
	int sum = 0;
	bool visit[MAX_N];
	priority_queue<edge> pri_q;
	memset(visit, 0, sizeof(visit));

	pri_q.push(make_edge(1, 0));
	
	while(!pri_q.empty()){
		edge p = pri_q.top();
		pri_q.pop();
		
		if(visit[p.to]) continue;
		visit[p.to] = true;
		sum += p.cost;
		
		//cout << p.to << " " << p.cost << " " << sum << endl;
		
		for(int i = 0; i < G[p.to].size(); i++)
			if(!visit[G[p.to][i].to])
				pri_q.push(G[p.to][i]);
	}
	
	for(int i = 1; i <= V; i++)
		if(!visit[i]) return -1;
	
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> V >> N;
	
	for(int i = 0; i < N; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		add_edge(from, to, cost);
	}
		
	cout << Prim() << endl;
	
	return 0;
}