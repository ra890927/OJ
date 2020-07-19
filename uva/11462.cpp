#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, k;
	int cnt[101];
	
	while(cin >> N){
		if(!N) break;

		int res = 0;
		
		memset(cnt, 0, sizeof(cnt));
		
		for(int i = 0; i < N; i++){
			cin >> k;
			res = max(res, k);
			cnt[k] += 1;
		}

		cnt[res] -= 1;
		
		for(int i = 0; i < 101; i++)
			for(int j = 0; j < cnt[i]; j++)
				printf("%d ", i);
		printf("%d\n", res);
	}
	
	return 0;
}