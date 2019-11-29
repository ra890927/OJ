#include <iostream>
#include <cstring>
#define MAXN 20
#define MAXM 20
using namespace std;

int N, M, sum;
char R[MAXM][MAXN];
bool walk[MAXM][MAXN];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x){
	sum++;
	walk[y][x] = false;
	for(int i = 0; i < 4; i++){
		int h = y + dy[i];
		int k = x + dx[i];
		if(h >= 0 && h < M && k >= 0 && k < N){
			if(walk[h][k]){
				dfs(h, k);
			}
		}
	}
}
int main(){
	while(cin >> N >> M){
		int p = 0, q = 0;
		if(!N && !M) break;
		memset(R, 0, sizeof(R));
		memset(walk, 0, sizeof(walk));
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				cin >> R[i][j];
				if(R[i][j] == '@'){
					p = i;
					q = j;
					walk[i][j] = true;
				}
				if(R[i][j] == '.')
					walk[i][j] = true;
			}
		}
		sum  = 0;
		dfs(p, q);
		cout << sum << endl;
	}
	return 0;
}
