#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int x, k;
		cin >> x >> k;
		if(x % k == 0)
			cout << "0 " << k << endl;
		else
			cout << -x << " " << x << endl;
	}
	return 0;
}