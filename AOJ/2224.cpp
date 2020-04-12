#include <bits/stdc++.h>
#define MAX_V 10000 + 1
using namespace std;

struct node{
	int x, y;
};

struct edge{
	int from, to;
	double cost;
	
	bool operator < (const edge &other) const{
		return cost > other.cost;
	}
};

int V, E;
int root[MAX_V];
node n[MAX_V];
vector<edge> G;

void init(){
	for(int i = 1; i <= V; i++)
		root[i] = i;
}

int find(int x){
	if(x == root[x]) return x;
	return find(root[x]);
}

bool same(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		root[a] = b;
		return true;
	}
	else return false;
}

double Kruskal(){
	init();
	double sum = 0;
	sort(G.begin(), G.end());
		
	for(int i = 0; i < G.size(); i++){
		edge e = G[i];
		if(same(e.from, e.to))
			sum += e.cost;
	}
	
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double all = 0, ans = 0;
	
	cin >> V >> E;
	
	for(int i = 1; i <= V; i++)
		cin >> n[i].x >> n[i].y;
	
	for(int i = 0; i < E; i++){
		edge e;
		int from, to;
		cin >> from >> to;
		e.from = from, e.to = to;
		e.cost = sqrt((n[from].x - n[to].x) * (n[from].x - n[to].x) + (n[from].y - n[to].y) * (n[from].y - n[to].y));
		G.push_back(e);
		all += e.cost;
	}
	
	ans = Kruskal();
	ans = all - ans;
	printf("%.3lf", ans);
	
	return 0;
}