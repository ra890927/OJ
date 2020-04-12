#include <cstdio>
#include <algorithm>
#define MAX_N 25000 + 1
using namespace std;

struct node{
	int s, e;
	
	bool operator < (const node &other) const{
		if(s == other.s) return e > other.e;
		else return s < other.s;
	}
};

int main(){
	int N, end;
	node n[MAX_N];
	scanf("%d %d", &N, &end);
	
	for(int i = 0; i < N; i++)
		scanf("%d %d", &n[i].s, &n[i].e);
	sort(n, n + N);
	
	int i = 0, temp = 0, ans = 0;
	while(i < N && temp < end){
		ans++;
		int top = temp;
		if(n[i].s > temp + 1) break;
		
		while(i < N && n[i].s <= temp + 1){
			top = max(top, n[i].e);
			i++;
		}
		
		temp = top;
	}
	
	if(temp < end) printf("-1\n");
	else printf("%d\n", ans);
	
	return 0;
}