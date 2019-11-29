#include <iostream>
#include <vector>
#define MAXN 100000 + 1
using namespace std;

int N;
long long int H;
bool used[MAXN];
int f[MAXN], d[MAXN];

void dfs(int k){
	if(f[k] == 0) return;
	d[f[k]] = max(d[f[k]], d[k] + 1);
	dfs(f[k]);
}

int main(){
	int a, k;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> k;
		while(k--){
			cin >> a;
			used[i] = true;
			f[a] = i;
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(f[i] == 0) cout << i << endl;
		if(!used[i]) dfs(i);
	}
	
	for(int i = 1; i <= N; i++) H += d[i];
	cout << H << endl;
	return 0;
}
