#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pair;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, T;
	cin >> T;

	while(T--){
		queue<Pair> que;
		priority_queue<int> pri_q;
		cin >> N >> M;

		int k, time = 0;
		for(int i = 0; i < N; i++){
			cin >> k;
			pri_q.push(k);
			que.push(make_pair(i, k));
		}

		while(!que.empty()){
			Pair temp = que.front();
			que.pop();

			if(temp.second == pri_q.top()){
				time += 1;
				pri_q.pop();

				if(temp.first == M){
					printf("%d\n", time);
					break;
				}
			}
			else que.push(temp);
		}
	}

	return 0;
}