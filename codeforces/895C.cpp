#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN 100000 + 10
#define MAXS (1 << 19)
using namespace std;

int N;
int a[MAXN];
bool used[MAXS]; 
bool not_prime[71];
vector<int> s, prime;
const int mod = 1e9 + 7;

void prime_sieve(){
	for(int i = 2; i < 71; i++){
		if(!not_prime[i]) prime.push_back(i);
		for(int j = 0; j * i < 71; j++)
			not_prime[i * j] = true;
	}
}

void init(){
	prime_sieve();
	for(int i = 0; i < N; i++){
		int n = a[i], res = 0;
		for(int j = 0; j < prime.size(); j++){
			int k = 0;
			while(n % prime[j]== 0){
				n /= prime[j];
				k = 1 - k;
			}
			res |= k << j;
			a[i] = res;
		}
	}
}

void solve(){
	init();
	long long res = 1;
	used[0] = true;
	s.push_back(0);
	for(int i = 0; i < N; i++){
		if(used[a[i]]) res = res * 2 % mod;
		else{
			int tmp = s.size();
			for(int j = 0; j < tmp; j++){
				s.push_back(s[j] ^ a[i]);
				used[s[j] ^ a[i]] = true;
			}
		}
	}
	cout << res - 1 << endl;
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%I64d", a + i);
	}
	solve();
	return 0;
}
