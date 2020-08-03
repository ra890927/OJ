#include <bits/stdc++.h>
using namespace std;

int N;
int arr[13];
int output[6];
bool used[13] = {0};

void dfs(int index, int size){
	if(size == 6){
		for(int i = 0; i < 5; i++)
			printf("%d ", output[i]);
		printf("%d\n", output[5]);

		return;
	}

	for(int i = index; i < N; i++){
		if(!used[i]){
			used[i] = true;
			output[size] = arr[i];
			dfs(i + 1, size + 1);
			used[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int count = 0;

	while(cin >> N){
		if(!N) break;

		if(count++) printf("\n");

		for(int i = 0; i < N; i++)
			cin >> arr[i];

		dfs(0, 0);
	}

	return 0;
}