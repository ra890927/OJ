#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100000 + 100
#define INF 0x3f3f3f3f
using namespace std;

int N, q;
const int mod = 1e9 + 7;
int a[MAXN], t[(1 << 20) + 10];
long long res[MAXN];
vector<int> s;

void solve(){
	memset(t, 0x3f, sizeof(t));
	t[0] = 0;
	res[0] = 1;
	s.push_back(0);
	
	for(int i = 1; i <= N; i++){
		res[i] = res[i - 1];
		if(t[a[i]] < INF) res[i] = res[i] * 2 % mod;
		else{
			int tmp = s.size();
			for(int j = 0; j < tmp; j++){
				t[s[j] ^ a[i]] = i;
				s.push_back(s[j] ^ a[i]);
			}
		}
	}
	int l, x;
	while(q--){
		cin >> l >> x;
		if(t[x] <= l) cout << res[l] << endl;
		else cout <<"0"<<endl;
	}
}
int main(){
	cin >> N >> q;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	solve();
	return 0;
}
