#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 10000 + 1
#define MAXK 1e7
using namespace std;

struct Seg{
	int L, R;
}s[MAXN];

bool cmp(Seg &a, Seg &b){
	if(a.L == b.L) a.R < b.R;
	return a.L < b.L;
}

int main(){
	int N;
	while(cin >> N){
		memset(s, 0, sizeof(s));
		for(int i = 0; i < N; i++)
			cin >> s[i].L >> s[i].R;
		s[N].L = s[N].R = MAXK;
		sort(s, s + N, cmp);
		int st = s[0].L, ed = s[0].R;
		int ans = 0;
		for(int i = 1; i <= N; i++){
			if(s[i].L <= ed)
				ed = max(s[i].R, ed);
			else{
				ans += ed - st;
				st = s[i].L, ed = s[i].R;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
