#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdio> 
#define MAXN 25000
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, T;
	cin >> N >> T;
	pair<int, int> time[MAXN];
	for(int i = 0; i < N; i++)
		scanf("%d%d", &time[i].first, &time[i].second);
	sort(time, time + N);
	
	int ans = 1, i = 0;
	priority_queue<int> q;
	do i++; while(time[i].first == 1);
	int last = time[i - 1].second;
	if(time[i - 1].first == 1){
		while(i < N){
			for(; i < N; i++){
				if(time[i].first <= last + 1)
					q.push(time[i].second);
				else break;
			}
			if(!q.empty()){
				if(last < q.top()){
					last = q.top();
					ans++;
				}
			}
			while(!q.empty()) q.pop();
		}
	}
	printf("%d\n", last < T ? -1 : ans);
	return 0;
}
