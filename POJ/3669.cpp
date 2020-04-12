#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 400 + 1
using namespace std;

int N, d[MAXN][MAXN];
const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};
struct Node{
	int x, y, t;
};

int bfs(){
	if(d[0][0] == 0)
		return -1;
	else if(d[0][0] == -1)
		return 0;
	Node res;
	res.x = 0, res.y = 0, res.t = 0;
	queue<Node> q;
	q.push(res);
	while(!q.empty()){
		res = q.front();
		q.pop();
		Node k;
		for(int i = 0; i < 4; i++){
			k.x = res.x + dx[i];
			k.y = res.y + dy[i];
			k.t = res.t + 1;
			if(k.x >= 0 && k.x <= 400 && k.y >= 0 && k.y <= 400){
				if(d[k.x][k.y] == -1)
					return k.t;
				if(d[k.x][k.y] > res.t + 1){
					d[k.x][k.y] = res.t;
					q.push(k);
				}
			}
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d", &N)){
		int x, y, t;
		memset(d, -1, sizeof(d));
		for(int i = 0; i < N; i++){
			scanf("%d %d %d", &x, &y, &t);
			for(int j = 0; j < 5; j++){
				int h = x + dx[j];
				int k = y + dy[j];
				if(h >= 0 && h <= 400 && k >= 0 && k <= 400){
					if(d[h][k] == -1) d[h][k] = t;
					else d[h][k] = min(d[h][k], t);
				}
			}
		}
		printf("%d\n", bfs());
	}
	
	return 0;
}
