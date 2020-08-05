#include <bits/stdc++.h>
#define MAX_N 10000 + 1
#define INF 1e9
using namespace std;

int N;
int arr[MAX_N];

void solve(){
	int temp[MAX_N];
	int L[MAX_N], R[MAX_N];

	fill(temp, temp + N, INF);
	for(int i = 0; i < N; i++){
		*lower_bound(temp, temp + N, arr[i]) = arr[i];
		L[i] = lower_bound(temp, temp + N, INF) - temp;
	}		

	fill(temp, temp + N, INF);
	for(int i = N - 1; i >= 0; i--){
		*lower_bound(temp, temp + N, arr[i]) = arr[i];
		R[i] = lower_bound(temp, temp + N, INF) - temp;
	}

	int ans = 1;
	for(int i = 0; i < N; i++)
		ans = max(ans, min(L[i], R[i]));

	printf("%d\n", ans * 2 - 1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N){
		memset(arr, 0, sizeof(arr));

		for(int i = 0; i < N; i++)
			cin >> arr[i];

		solve();
	}

	return 0;
}