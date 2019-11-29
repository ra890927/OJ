#include <bits/stdc++.h>
#define MAXN 200 + 1
using namespace std;

int N, a, b;
int an[MAXN], bn[MAXN];
int v[5][5] = {
{-1, 0, 1, 1, 0},
{1, -1, 0, 1, 0},
{0, 1, -1, 0, 1},
{0, 0, 1, -1, 1},
{1, 1, 0, 0, -1}
};
void solve(){
	int p = 0, q = 0;
	for(int i = 1; i <= N; i++){
		if(v[an[(i - 1) % a]][bn[(i - 1) % b]] == 1) p++;
		else if(v[an[(i - 1) % a]][bn[(i - 1) % b]] == 0) q++;
	}
	cout << p << " " << q << endl;
}

int main(){
	while(cin >> N >> a >> b){
		memset(an, 0, sizeof(an));
		memset(bn, 0, sizeof(bn));
		for(int i = 0; i < a; i++) scanf("%d", &an[i]);
		for(int i = 0; i < b; i++) scanf("%d", &bn[i]);
		solve();
	}
	return 0;
}
