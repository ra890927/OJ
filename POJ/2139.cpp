#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX_V 300 + 5
#define INF 1E9
using namespace std;

int V, N;
int data[MAX_V];
int d[MAX_V][MAX_V];

void solve(){
	for(int i = 1; i <= V; i++)
		d[i][i] = 0;
	
	for(int k = 1; k <= V; k++)
		for(int i = 1; i <= V; i++)
			for(int j = 1; j <= V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = INF;
    for(int i = 1; i <= V; i++){
        int sum = 0;
        for(int j = 1; j <= V; j++)
            sum += d[i][j];
        ans = min(ans, sum);
    }

    cout << ans * 100 / (V - 1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    cin >> V >> N;
	
	for(int i = 1; i <= V; i++)
		fill(d[i], d[i] + V + 1, INF);
	
    for(int k = 0; k < N; k++){
        cin >> cnt;
        memset(data, 0, sizeof(data));
        for(int i = 0; i < cnt; i++)
            cin >> data[i];

        for(int i = 0; i < cnt; i++){
            for(int j = i + 1; j < cnt; j++){
                d[data[i]][data[j]] = 1;
				d[data[j]][data[i]] = 1;
			}
		}
    }
	
    solve();
	
    return 0;
}