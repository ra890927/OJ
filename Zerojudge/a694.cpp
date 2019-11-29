#include <iostream>
#include <cstring>
#define MAXN 500 + 1
using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M){
		int map[MAXN][MAXN];
		int sum[MAXN][MAXN];
		memset(sum, 0, sizeof(sum));
		
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++){
				scanf("%d", &map[i][j]);
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
			}
		
		while(M--){
			int a, b, p, q;
			cin >> a >> b >> p >> q;
			cout << sum[p][q] - sum[a-1][q] - sum[p][b-1] + sum[a-1][b-1] << endl;
		}
	}
	return 0;
} 
