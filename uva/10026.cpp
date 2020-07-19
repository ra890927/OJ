#include <bits/stdc++.h>
#define MAX_N 1000 + 1
using namespace std;

struct Wrok{
	int time;
	int cost;
	int index;

	bool operator < (const Wrok &other) const{
		if(cost * other.time == time * other.cost) return index < other.index;
		else return cost * other.time > time * other.cost;
	}
};

int main(){
	int N, T;

	cin >> T;

	while(T--){
		Wrok arr[MAX_N];

		cin >> N;

		for(int i = 0; i < N; i++){
			arr[i].index = i + 1;
			cin >> arr[i].time >> arr[i].cost;
		}

		sort(arr, arr + N);

		for(int i = 0; i < N; i++){
			if(i) printf(" ");
			printf("%d", arr[i].index);
		}
		printf("\n");
	}

	return 0;
}