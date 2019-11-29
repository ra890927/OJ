#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int k[20], u = -1, l = 101;
		for(int i = 0; i < n; i++){
			cin >> k[i];
			if(k[i] < 60 && k[i] > u) u = k[i];
			else if(k[i] >= 60 && k[i] < l) l = k[i];
		}
		sort(k, k + n);
		for(int i = 0; i < n-1; i++) cout << k[i] << " ";
		cout << k[n - 1] << endl;
		if(u == -1) cout << "best case" << endl;
		else cout << u << endl;
		if(l == 101) cout << "worst case" << endl;
		else cout << l << endl;
	}
	return 0;
}
