#include <bits/stdc++.h>
using namespace std;

int bfs(int s, int t, vector<int> G[21]){
	int dis[21] = {0};
	queue<int> que;

	dis[s] = 0;
	que.push(s);

	while(!que.empty()){
		int p = que.front();
		que.pop();

		for(int &n : G[p]){
			if(!dis[n]){
				dis[n] = dis[p] + 1;
				if(n == t) return dis[n];
				que.push(n);
			}
		}
	}

	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, k, count = 1;

	while(cin >> t){
		vector<int> G[21];

		while(t--){
			cin >> k;
			G[1].push_back(k);
			G[k].push_back(1);
		}

		for(int i = 2; i < 20; i++){
			cin >> t;
			while(t--){
				cin >> k;
				G[i].push_back(k);
				G[k].push_back(i);
			}
		}

		cin >> t;
		printf("Test Set #%d\n", count++);

		while(t--){
			int p, q;
			cin >> p >> q;
			if(p < 10 && q < 10) printf(" %d to  %d: %d\n", p, q, bfs(p, q, G));
			else if(p < 10) printf(" %d to %d: %d\n", p, q, bfs(p, q, G));
			else if(q < 10) printf("%d to  %d: %d\n", p, q, bfs(p, q, G));
			else printf("%d to %d: %d\n", p, q, bfs(p, q, G));
		}

		printf("\n");
	}

	return 0;
}