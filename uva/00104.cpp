#include <bits/stdc++.h>
#define MAX_N 20 + 1
using namespace std;

int N;
int path[MAX_N][MAX_N][MAX_N];
double dp[MAX_N][MAX_N][MAX_N];

void Floyd_Warshall(){
	for(int s = 2; s <= N; s++){
		for(int k = 1; k <= N; k++){
			for(int i = 1; i <= N; i++){
				for(int j = 1; j <= N; j++){
					if(dp[i][k][s - 1] * dp[k][j][1] > dp[i][j][s]){
						dp[i][j][s] = dp[i][k][s - 1] * dp[k][j][1];
						path[i][j][s] = k;
					}
				}
			}
		}

		for(int i = 1; i <= N; i++){
			if(dp[i][i][s] > 1.01){
				stack<int> S;

				int j = i;
				while(s - 1)
					S.push(j = path[i][j][s--]);

				printf("%d ", i);
				while(!S.empty()){
					printf("%d ", S.top());
					S.pop();
				}
				printf("%d\n", i);

				return;
			}
		}
	}

	printf("no arbitrage sequence exists\n");
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N){
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));

		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i == j) dp[i][j][1] = 1.0;
				else cin >> dp[i][j][1];

				path[i][j][1] = 1;
			}
		}

		Floyd_Warshall();
	}

	return 0;
}