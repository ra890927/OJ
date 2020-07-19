#include <bits/stdc++.h>
#define MAX_N 1000 + 5
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	int arr[MAX_N];
	
	while(cin >> N){
		memset(arr, 0, sizeof(arr));
		
		int ans = 0;
		
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		
		for(int i = 0; i < N; i++){
			for(int j = N - 1; j > i; j--){
				if(arr[j] < arr[j - 1]){
					ans += 1;
					swap(arr[j], arr[j - 1]);
				}
			}
		}
		
		printf("Minimum exchange operations : %d\n", ans);
	}
	
	return 0;
}