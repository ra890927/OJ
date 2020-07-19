#include <bits/stdc++.h>
#define MAX_N 500 + 1
#define INF 1e9
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, T;

	cin >> T;

	while(T--){
		int ans = INF;
		int arr[MAX_N];

		cin >> N;

		for(int i = 0; i < N; i++)
			cin >> arr[i];

		for(int i = 0; i < N; i++){
			int sum = 0;

			for(int j = 0; j < N; j++)
				sum += abs(arr[i] - arr[j]);

			ans = min(ans, sum);
		}

		printf("%d\n", ans);
	}

	return 0;
}