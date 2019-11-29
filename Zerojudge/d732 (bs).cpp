#include <cstdio>
#define MAX_N 100000 + 1
using namespace std;

int main(){
	int N, K;
	while(~scanf("%d %d", &N, &K)){
		int k, arr[N+1];
		for(int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		
		while(K--){
			scanf("%d", &k);
			int l = 1, r = N + 1, mid;
			while(r > l){
				mid = (l + r) / 2;
				if(arr[mid] == k) break;
				else if(arr[mid] > k) r = mid;
				else l = mid + 1;
			}
			if(arr[mid] == k) printf("%d\n", mid);
			else printf("0\n");
		}
	}
	return 0;
}