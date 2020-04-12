#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 100000 + 1
using namespace std;

int N, k, ans;
vector<int> v[MAXN];

int dfs(int k){
	if(v[k].size() == 0) return 0;
	if(v[k].size() == 1) return dfs(v[k][0]) + 1;
	else{
		int m1 = 0, m2 = 0;
		for(int i = 0; i < v[k].size(); i++){
			int res = dfs(v[k][i]) + 1;
			if(res > m1){
				m2 = m1;
				m1 = res;
			}
			else if(res > m2) m2 = res;
		}
		ans = max(ans, m1 + m2);
		return m1;	
	}
}

int main(){
	while(cin >> N){
		k = 0, ans = 0;
		int used[N] = {};
		for(int i = 1; i < N; i++){
			int p, q;
			scanf("%d %d", &p, &q);
			v[p].push_back(q);
			used[q] = 1;
		}
		for(int i = 0; i < N; i++)
			if(used[i] == 0) k = dfs(i);
		ans = max(ans, k);
		cout << ans << endl;
		for(int i = 0; i < N; i++)
			v[i].clear();
	}
}
