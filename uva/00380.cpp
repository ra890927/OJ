#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int dfs(int in, int time,
				unordered_map<int, map<int,P>> &forwards,
				unordered_set<int> &visited){
	if(visited.count(in)) return 9999;
	visited.insert(in);

	if(forwards[in].count(time))
		return dfs(forwards[in][time].second, time, forwards, visited);
	
	auto it = forwards[in].lower_bound(time);
	if(it != forwards[in].begin()){
		--it;
		if(it->first + (it->second).first >= time)
			return dfs((it->second).second, time, forwards, visited);
	}

	return in;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	printf("CALL FORWARDING OUTPUT\n");

	for(int i = 0; i < T; i++){
		printf("SYSTEM %d\n", i + 1);

		int in, start, end, out, call, time;
		unordered_map<int, map<int, P>> forwards;
		while(cin >> in, in){
			cin >> start >> end >> out;
			forwards[in][start] = {end, out};
		}

		while(cin >> time, time != 9000){
			unordered_set<int> visited;
			cin >> call;
			printf("AT %04d CALL TO %04d RINGS %04d\n", time, call, dfs(call, time, forwards, visited));
		}
	}

	printf("END OF OUTPUT\n");

	return 0;
}