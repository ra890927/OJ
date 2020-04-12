#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 30
using namespace std;

bool res;
int N, M, pointer;
int m[MAXN], ans[MAXN];

void dfs(int k, int sum){
	if(sum == M){
		for(int i = 0; i < pointer; i++)
			cout << ans[i] << " ";
		cout << endl;
		res = true;
		return;
	}
	if(k == N || sum + m[k] > M) return;
	ans[pointer++] = m[k];
	dfs(k + 1, sum + m[k]);
	pointer--;
	dfs(k + 1, sum); 
	
}

int main(){
	int sum = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> m[i], sum += m[i];
	sort(m, m + N);
	if(sum >= M) dfs(0, 0);
	if(!res) cout << "-1" << endl;
	return 0;
} 
