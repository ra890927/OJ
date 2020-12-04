#include <bits/stdc++.h>
#define MAX_N 100000 + 1
using namespace std;

int N, K;
int arr[MAX_N];
bool is_used[MAX_N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		memset(arr, 0, sizeof(arr));
		memset(is_used, 0, sizeof(is_used));

		cin >> N >> K;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			is_used[arr[i]] = true;
		}

		int ans = INT_MAX;
		for(int k = 1; k < 101; k++){
			if(is_used[k]){
				int res = 0;
				for(int i = 0; i < N; i++){
					if(arr[i] != k){
						res += 1;
						i += K - 1;
					}
				}
				ans = min(res, ans);
			}
		}

		cout << ans << endl;
	}

	return 0;
}