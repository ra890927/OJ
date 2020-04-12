#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#define MAXN 100
using namespace std;
typedef pair<int, int> P;

int N;
string d[MAXN];
queue<P> que;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void bfs(int p, int q){
	que.push(P(p, q));
	while(!que.empty()){
		P k = que.front();
		que.pop();
		d[k.first][k.second] = '+';
		for(int i = 0; i < 4; i++){
			int a = k.first + dy[i];
			int b = k.second + dx[i];
			if(a >= 0 && a < N && b >= 0 && b < N && d[a][b] == '-')
				que.push(P(a, b));
		}
	}
}

int main(){
	int p, q;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> d[i];
	cin >> p >> q;
	bfs(p, q);
	for(int i = 0; i < N; i++)
		cout << d[i] << endl;
	return 0; 
}
