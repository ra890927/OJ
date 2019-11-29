#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 100000 + 1

using namespace std;
typedef long long ll;

int N, M;
ll c[MAXN];
bool used[MAXN];
vector<int> v[MAXN];

ll dfs(int k){
	ll res = c[k];
	used[k] = true;
	for(int i = 0; i < v[k].size(); i++){
		if(!used[v[k][i]]){
			res = min(res, dfs(v[k][i]));
		}
	}
	return res;
}

int main(){
	int p, q;
	ll sum = 0;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		scanf("%d", &c[i]);
	while(M--){
		scanf("%d %d", &p, &q);
		v[p].push_back(q);
		v[q].push_back(p);
	}
	
	for(int i = 1; i <= N; i++)
		if(!used[i]) sum += dfs(i);
	cout << sum << endl;
	return 0;
}
