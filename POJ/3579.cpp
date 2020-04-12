#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 100000 + 1
using namespace std;

int N, C;
int arr[MAX_N];

bool check(int x){
	int cnt = 0, temp;

	for(int i = 0; i < N; i++){
		temp = N - (lower_bound(arr, arr + N, arr[i] + x) - arr);
		if(temp == 0) break;
		cnt += temp;
	}
	
	return cnt > C / 2;
}

int main(){
	while(cin >> N){
		memset(arr, 0, sizeof(arr));

		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr + N);

		C = (N - 1) * N / 2;

		int lb = 0, ub = arr[N - 1] - arr[0] + 1, mid;
		while(ub - lb > 1){
			mid = (lb + ub) / 2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}

		printf("%d\n", lb);
	}

	return 0;
}