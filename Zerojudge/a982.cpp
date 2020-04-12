#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
using namespace std;
typedef pair<int, int> P;

int N;
int d[MAXN][MAXN];
char m[MAXN][MAXN];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void bfs(){
	queue<P> q;
	d[1][1] = 1;
	q.push(P(1, 1));
	while(!q.empty()){
		P t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int a = t.first + dy[i];
			int b = t.second + dx[i];
			if(a >= 0 && a < N && b >= 0 && b < N && m[a][b] == '.'){
				q.push(P(a, b));
				if(d[a][b] == 0) d[a][b] = d[t.first][t.second] + 1;
				else d[a][b] = min(d[a][b], d[t.first][t.second] + 1);
			}
				
			if(a == N-2 && b == N-2){
				cout << d[a][b] << endl;
				return;
			}
		}
	}


	cout << "No solution!" << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> m[i][j];
	bfs();
	return 0;
}
