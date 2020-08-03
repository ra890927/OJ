#include <iostream>
#define MAX_N 100000 + 1
using namespace std;

int N, M;
int arr[MAX_N];

bool check(int limit){
	int sum = 0, count = 1;

	for(int i = 0; i < N; i++){
		if(arr[i] > limit) return false;

		if(sum + arr[i] <= limit)
			sum += arr[i];
		else{
			sum = arr[i];

			count++;
		}
	}

	return count <= M;
}

int main(){
	int lb = 0, ub = 1, mid;

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
		ub += arr[i];
	}

	while(ub - lb > 1){
		mid = (lb + ub) / 2;

		if(check(mid)) ub = mid;
		else lb = mid;
	}

	cout << ub << endl;

	return 0;
}