#include <cstdio>
#include <cstring>
#define MAX_N 100000
using namespace std;

int main(){
	int N, k, n, s;
	while(~scanf("%d", &N)){
		int f;
		int array[MAX_N] = {0};
		while(N--){
			scanf("%d %d ", &k, &n);
			while(n--){
				scanf("%d", &s);
				array[s] = k;
			}
		}
		scanf("%d", &f);
		printf("%d\n", array[f]);
	}
	return 0;
}