#include <bits/stdc++.h>
#define MAXN 100000 + 5
using namespace std;

int main(){
	int n, m;
	while(cin >> n >> m){
		int p, q;
		int s[MAXN] = {0};
		for(int i = 1; i <= n; i++){
			scanf("%d", &s[i]);
			s[i] = s[i - 1] + s[i];
		}
		while(m--){
			cin >> p >> q;
			cout << s[q] - s[p - 1] << endl;
		}
	}
	return 0;
}
