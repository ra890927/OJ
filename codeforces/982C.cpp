#include <cstdio>
#include <vector>
#define MAXN 100000 + 1
using namespace std;

int N, ans = 0;
vector<int> v[MAXN];

int dfs(int n, int k){
	int res = 0;
	for(int i = 0; i < v[n].size(); i++){
		if(v[n][i] != k){
			int tmp = dfs(v[n][i], n);
			if(tmp % 2 == 0) ans++;
			res += tmp;
		}
	}
	return res + 1;
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		v[p].push_back(q);
		v[q].push_back(p);
	}
	if(N & 1){
		printf("-1\n");
		return 0;
	}
	
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
