#include <iostream>
using namespace std;

int main(){
	long long N, K, W;
	while(cin >> N >> K >> W){
		long long cnt = N;
		while(N >= K){
			long long num = N / K;
			N %= K;
			cnt += num * W;
			N += num * W;
		}
		cout << cnt << endl;
	}
	return 0;
}
