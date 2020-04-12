#include <cstdio>
#include <map>
#define MAX_N 100000 + 1
using namespace std;

int main(){
	int N, K;
	while(~scanf("%d %d", &N, &K)){
		int k;
		map<int, int> m;
		map<int, int>::iterator it;
		for(int i = 1; i <= N; i++){
			scanf("%d", &k);
			m[k] = i;
		}
		
		while(K--){
			scanf("%d", &k);
			it = m.find(k);
			if(it != m.end())
				printf("%d\n", it -> second);
			else
				printf("0\n");
		}
	}
	return 0;
}