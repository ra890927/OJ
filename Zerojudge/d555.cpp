#include <cstdio>
#include <utility>
#include <algorithm>
#define MAX_N 500000 + 1
using namespace std;
typedef pair<int, int> P;

P dot[MAX_N];
bool cmp(P &a, P &b){
	if(a.first != b.first)
		return a.first > b.first;
	else return a.second > b.second;
}

int main(){
	int k = 1, N;
	while(~scanf("%d", &N)){
		int cnt = 0, now = 0, last = -1;
		bool pick[MAX_N] = {};
		for(int i = 0; i < N; i++){
			scanf("%d %d", &dot[i].first, &dot[i].second);
			pick[i] = false;
		}
		sort(dot, dot + N, cmp);
		
		for(int i = 1; i < N; i++){
			if(dot[now].first != dot[i].first){
				if(dot[now].second > last){
					pick[now] = true;
					last = dot[now].second;
					cnt++;
				}
				now = i;
			}
		}
		if(dot[now].second > last){
			pick[now] = true;
			cnt++;
		}
		
		printf("Case %d:\n", k++);
		printf("Dominate Point: %d\n", cnt);
		for(int i = N-1; i >= 0; i--)
			if(pick[i])
				printf("(%d,%d)\n", dot[i].first, dot[i].second);
	}
	return 0;
}