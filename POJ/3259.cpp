#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_N 200 + 5
#define MAX_V 500 + 5
#define INF 1E9
using namespace std;

struct edge{
	int from, to, cost;
};

int V, E, N;
int d[MAX_V];
vector<edge> ed;

edge make_edge(int from, int to, int cost){
	edge e;
	e.from = from;
	e.to = to;
	e.cost = cost;
	return e;
}

void Bellman_ford(){
	memset(d, 0, sizeof(d));
	
	for(int i = 0; i < V; i++){
		for(int j = 0; j < ed.size(); j++){
			edge e = ed[j];
			if(d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				if(i == V - 1){
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	
	cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		ed.clear();
		int res[MAX_N];
		int a, b, cost;
		cin >> V >> E >> N;
		
		for(int i = 0; i < E; i++){
			cin >> a >> b >> cost;
			ed.push_back(make_edge(a, b, cost));
			ed.push_back(make_edge(b, a, cost));
		}
		
		for(int i = 0; i < N; i++){
			cin >> a >> b >> cost;
			res[i] = b;
			ed.push_back(make_edge(a, b, -cost));
		}
		
		Bellman_ford();
	}
	
	return 0;
}