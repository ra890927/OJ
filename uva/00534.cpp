#include <bits/stdc++.h>
#define MAX_N 200 + 1
using namespace std;
 
double x[MAX_N], y[MAX_N];
double d[MAX_N][MAX_N];
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, count = 1;
	while(cin >> N){
		if(!N) break;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(d, 0, sizeof(d));

		for(int i = 0; i < N; i++)
			cin >> x[i] >> y[i];

		for (int i = 0; i < N; i++){
			for (int j = 0; j < i; j++) {
				d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				d[j][i] = d[i][j];
			}
		}
		
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		
		printf("Scenario #%d\n", count++);
		printf("Frog Distance = %.3lf\n\n", d[0][1]);
	}

    return 0;
}