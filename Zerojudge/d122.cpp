#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	ll N;
	while(cin >> N){
		int ans = 0;
		while(N > 4){
			N -= N % 5;
			ans += N / 5;
			N /= 5;
		}
		cout << ans <<endl;
	}
	return 0;
}
