#include <bits/stdc++.h>
#define MAX_N 110
using namespace std;

struct Node{
	int v, k, cost;

	Node(){}
	Node(int a, int b, int c) : v(a), k(b), cost(c){}

	bool operator < (const Node &other) const{
		return cost > other.cost;
	}
};

int N, M;
int c[5];
bool lift[5][MAX_N];

void Dijkstra(){
	int d[5][MAX_N];
	priority_queue<Node> pri_q;

	for(int i = 0; i < 5; i++){
		fill(d[i], d[i] + MAX_N, INT_MAX);
		if(lift[i][0]){
			d[i][0] = 0;
			pri_q.push(Node(0, i, 0));
		}
	}

	while(!pri_q.empty()){
		Node p = pri_q.top();
		pri_q.pop();

		int u = p.v, id = p.k;
		if(d[id][u] < p.cost) continue;

		for(int i = 0; i < N; i++){
			if(lift[i][u] && d[i][u] > d[id][u] + 60){
				d[i][u] = d[id][u] + 60;
				pri_q.push(Node(u, i, d[i][u]));
			}
		}

		for(int i = 0; i < MAX_N; i++){
			if(lift[id][i]){
				int time = c[id] * abs(i - u);

				if(d[id][i] > d[id][u] + time){
					d[id][i] = d[id][u] + time;
					pri_q.push(Node(i, id, d[id][i]));
				}
			}
		}
	}

	int ans = INT_MAX;
	for(int i = 0; i < N; i++)
		ans = min(ans, d[i][M]);

	if(ans == INT_MAX) printf("IMPOSSIBLE\n");
	else printf("%d\n", ans);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N >> M){
		memset(c, 0, sizeof(c));
		memset(lift, 0, sizeof(lift));
		
		for(int i = 0; i < N; i++)
			cin >> c[i];
		cin.ignore();

		for(int i = 0; i < N; i++){
			int k;
			string s;
			stringstream ss;

			getline(cin, s);
			ss << s;
			while(ss >> k) lift[i][k] = true;
		}

		Dijkstra();
	}

	return 0;
}