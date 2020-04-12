#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int a[10];
bool flag;

void dfs(int x, int l, int r){
	if(x == 10){
		flag = true;
		return;
	}
	if(a[x] > l)
		dfs(x+1, a[x], r);
	else if(a[x] > r)
		dfs(x+1, l, a[x]);
	else flag = false;
}
int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		memset(a, 0, sizeof(a));
		for(int i = 0; i < 10; i++) scanf("%d", &a[i]);
		flag = false;
		dfs(0, 0, 0);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
