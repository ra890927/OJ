#include <iostream>
using namespace std;

int N;
int used[9], ans[9];

void dfs(int k){
	if(k == N){
		for(int i = 0; i < N; i++)
			cout << ans[i];
		cout <<endl;
		return;
	}
	for(int i = N; i >= 1; i--){
		if(used[i] == 0){
			used[i] = 1;
			ans[k] = i;
			dfs(k + 1);
			used[i] = 0;
		}
	}
}

int main(){
	while(cin >> N){
		dfs(0); 
	}
	return 0;
}
