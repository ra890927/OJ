#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;
typedef pair<int, int> Pair;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M;
bool visit[MAX_N][MAX_N];
string m[MAX_N];

void dfs(int y, int x){
	visit[y][x] = true;

	for(int i = 0; i < 8; i++){
		int q = x + dx[i];
		int p = y + dy[i];

		if(!visit[p][q] && p >= 0 && p < N && q >= 0 && q < M && m[p][q] == '@')
			dfs(p, q);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N >> M){
		if(N + M == 0) break;

		memset(visit, 0, sizeof(visit));

		for(int i = 0; i < N; i++)
			cin >> m[i];

		int count = 0;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(m[i][j] == '@' && !visit[i][j]){
					count += 1;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}