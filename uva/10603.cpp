#include <bits/stdc++.h>
#define MAX_V 200 + 1
#define INF 1e9
using namespace std;

struct State{
	int a, b, c, tol;
};

int a_vol, b_vol, c_vol, d;
int record[MAX_V], jug[MAX_V][MAX_V];

void init(){
	fill(record, record + MAX_V, INF);
	memset(jug, -1, sizeof(jug));
}

State build_state(int a, int b, int c, int tol){
	State ret;
	ret.a = a, ret.b = b, ret.c = c, ret.tol = tol;
	return ret;
}

void bfs(){
	queue<State> que;
	que.push(build_state(0, 0, c_vol, 0));

	while(!que.empty()){
		State temp = que.front();
		que.pop();

		int a = temp.a, b = temp.b, c = temp.c, total = temp.tol;

		if(total >= record[d]) continue;
		if(total >= jug[a][b] && jug[a][b] != -1) continue;

		jug[a][b] = total;

		record[a] = min(record[a], total);
		record[b] = min(record[b], total);
		record[c] = min(record[c], total);

		//A -> B
		if(a < b_vol - b) que.push(build_state(0, b + a, c, total + a));
		else que.push(build_state(a - (b_vol - b), b_vol, c, total + (b_vol - b)));
		//A -> C
		if(a < c_vol - c) que.push(build_state(0, b, c + a, total + a));
		else que.push(build_state(a - (c_vol - c), b, c_vol, total + (c_vol - c)));
		//B -> A
		if(b < a_vol - a) que.push(build_state(a + b, 0, c, total + b));
		else que.push(build_state(a_vol, b - (a_vol - a), c, total + (a_vol - a)));
		//B -> C
		if(b < c_vol - c) que.push(build_state(a, 0, c + b, total + b));
		else que.push(build_state(a, b - (c_vol - c), c_vol, total + (c_vol - c)));
		//C -> A
		if(c < a_vol - a) que.push(build_state(a + c, b, 0, total + c));
		else que.push(build_state(a_vol, b, c - (a_vol - a), total + (a_vol - a)));
		//C -> B
		if(c < b_vol - b) que.push(build_state(a, b + c, 0, total + c));
		else que.push(build_state(a, b_vol, c - (b_vol - b), total + (b_vol - b)));
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		init();
		cin >> a_vol >> b_vol >> c_vol >> d;
		bfs();
		int ans = d;
		while(record[ans] == INF) ans -= 1;
		printf("%d %d\n", record[ans], ans);
	}

	return 0;
}