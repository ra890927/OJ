#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;
typedef pair<double, double> Node;

int N;
Node arr[MAX_N];

double get_dis(Node &a, Node &b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void Prim(){
	double sum = 0.0;
	bool visit[MAX_N] = {0};
	double d[MAX_N] = {0};
	double w[MAX_N][MAX_N] = {0};

	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			w[i][j] = w[j][i] = get_dis(arr[i], arr[j]);

	visit[0] = true;
	for(int i = 0; i < N; i++)
		d[i] = w[0][i];

	for(int i = 0; i < N; i++){
		int u = -1;
		double temp = INT_MAX;

		for(int j = 0; j < N; j++){
			if(!visit[j] && temp > d[j]){
				temp = d[j];
				u = j;
			}
		}

		if(u == -1) break;

		sum += temp;
		visit[u] = true;

		for(int j = 0; j < N; j++)
			d[j] = min(d[j], w[u][j]);
	}

	printf("%.2lf\n", sum);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> arr[i].first >> arr[i].second;

		Prim();

		if(T) printf("\n");
	}

	return 0;
}