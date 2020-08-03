#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#define MAX_N 100000 + 1
using namespace std;

int N, K;
int arr[MAX_N];

bool check(int limit){
	int time = 0;

	for(int i = 0; i < N; i++){
		if(arr[i] < limit) break;

		time += (arr[i] - limit) / (K - 1);

		if((arr[i] - limit) % (K - 1)) time++;

		if(time > limit) return false;
	}

	return time <= limit;
}

int main(){
	while(cin >> N){
		memset(arr, 0, sizeof(arr));

		for(int i = 0; i < N; i++)
			cin >> arr[i];

		cin >> K;

		sort(arr, arr + N, greater<int>());

		int lb = 0, ub = arr[0], mid;

		if(K != 1){
			while(ub - lb > 1){
				mid = (lb + ub) / 2;
				
				if(check(mid)) ub = mid;
				else lb = mid;
			}
		}

		cout << ub << endl;
	}

	return 0;
}