#include <bits/stdc++.h>
#define MAX_N 50000 + 1
using namespace std;

int N, M;
int parent[MAX_N];
int height[MAX_N];

void init(){
	for(int i = 0; i <= N; i++){
		parent[i] = i;
		height[i] = 0;
	}
}

int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(height[x] > height[y])
		parent[y] = x;
	else if(height[x] == height[y]){
		parent[y] = x;
		height[x] += 1;
	}
	else
		parent[x] = y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, index = 1;

	while(cin >> N >> M){
		if(N + M == 0) break;

		init();

		for(int i = 0; i < M; i++){
			cin >> x >> y;

			x = find(x);
			y = find(y);

			if(x != y) unite(x, y);
		}

		int cnt = 0;

		for(int i = 1; i <= N; i++)
			if(parent[i] == i) cnt += 1;
		
		printf("Case %d: %d\n", index++, cnt);
	}

	return 0;
}