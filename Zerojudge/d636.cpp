#include <iostream>
using namespace std;

int main(){
	int a, b, k, ans = 1;
	const int mod = 10007;
	cin >> a >> b;
	k = a % mod;
	while(b){
		if(b & 1){
			ans *= k;
			ans %= mod;
		}
		k *= k;
		k %= mod;
		b >>= 1;
	}
	cout << ans << endl;
	return 0;
}