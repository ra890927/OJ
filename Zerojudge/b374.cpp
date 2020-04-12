#include <iostream>
#define MAXN 30000 + 1
using namespace std;

int main(){
	int k, N, res = 0;
	int cnt[MAXN] = {0};
	cin >> N;
	while(N--){
		cin >> k;
		cnt[k]++;
		res = max(res, cnt[k]);
	}
	for(int i = 1; i < MAXN; i++)
		if(cnt[i] == res)
			cout << i << " " << cnt[i] << endl;
	return 0;
}
