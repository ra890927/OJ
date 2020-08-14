#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int C[15], ans[15];
vector<int> G[15];

void init(){
	memset(C, 0, sizeof(C));
	for(int i = 0; i < 15; i++)
		G[i].clear();
}

void Topological_sort(){
	int d = 0;
	queue<int> que;

	for(int i = 0; i <= N; i++)
		if(!C[i]) que.push(i);

	while(!que.empty()){
		int sz = que.size();
		for(int i = 0; i < sz; i++){
			int p = que.front();
			que.pop();

			ans[p] = d;
			for(int &n : G[p]){
				C[n] -= 1;

				if(!C[n]) que.push(n);
			}
		}
		d += 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		init();
		cin >> N >> s;

		int k = 0;
		for(int i = 1; i <= N; i++){
			for(int j = i; j <= N; j++){
				if(s[k] == '+'){
					G[i - 1].push_back(j);
					C[j] += 1;
				}
				else if(s[k] == '-'){
					G[j].push_back(i - 1);
					C[i - 1] += 1;
				}
				k++;
			}
		}

		Topological_sort();

		for(int i = 1; i < N; i++)
			printf("%d ", ans[i] - ans[i - 1]);
		printf("%d\n", ans[N] - ans[N - 1]);
	}

	return 0;
}