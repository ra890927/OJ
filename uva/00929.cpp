#include <bits/stdc++.h>
#define MAX_N 1000 + 1
using namespace std;

struct Node{
	int x, y, cost;

	Node(){};
	Node(int a, int b, int k) : x(a), y(b), cost(k){}

	bool operator < (const Node &other) const{
		return cost > other.cost;
	}
};

int N, M;
int arr[MAX_N][MAX_N];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void Dijkstra(){
	int d[MAX_N][MAX_N];
	priority_queue<Node> pri_q;
	for(int i = 0; i < N; i++)
		fill(d[i], d[i] + M, INT_MAX);

	d[0][0] = arr[0][0];
	pri_q.push(Node(0, 0, d[0][0]));

	while(!pri_q.empty()){
		Node u = pri_q.top();
		pri_q.pop();

		if(u.cost > d[u.y][u.x]) continue;

		for(int i = 0; i < 4; i++){
			int p = u.x + dx[i];
			int q = u.y + dy[i];

			if(p >= 0 && p < M && q >= 0 && q < N && d[q][p] > arr[q][p] + u.cost){
				d[q][p] = arr[q][p] + u.cost;
				pri_q.push(Node(p, q, d[q][p]));
			}
		}
	}

	printf("%d\n", d[N - 1][M - 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N >> M;
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				cin >> arr[i][j];

		Dijkstra();
	}

	return 0;
}