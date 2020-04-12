#include <cstdio>
#define MAXN 10000 + 1
using namespace std;

int main(){
	int N, M, p, q;
	while(~scanf("%d %d", &N, &M)){
		int cnt = 0, edge[MAXN] = {0};
		
		while(M--){
			scanf("%d %d", &p, &q);
			edge[p]++;
			edge[q]++;
		}
		
		for(int i = 1; i <= N; i++)
			if(edge[i] % 2) cnt++;
		if(!cnt || cnt == 2) printf("YES\n");
		else printf("NO\n");		
	}

	return 0;
}
