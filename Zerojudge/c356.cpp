#include <cstdio>
#define MAXN 25000000
using namespace std;

int main(){
	char c;
	int N, cnt;
	while(~scanf("%d", &N)){
		scanf("%c", &c);
		printf("%c", c);
		
		cnt = N;
		for(int i = 1; i < N * N; i++, cnt--){
			scanf("%c", &c);
			if(!cnt){
				printf("%c", c);
				cnt = N + 1;
			}
		}
		printf("\n");
	}
	return 0;
}
