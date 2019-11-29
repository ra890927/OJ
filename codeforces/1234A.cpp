#include <iostream>
using namespace std;

int main(){
	double N, T;
	cin >> T;
	while(T--){
		double sum = 0;
		cin >> N;
		for(int i = 0; i < N; i++){
			int k;
			cin >> k;
			sum += k;
		}
		int ans = sum / N;
		double ans1 = sum / N;
		if(ans1 == ans) cout << ans << endl;
		else cout << ans + 1 << endl;
	}
	return 0;
}