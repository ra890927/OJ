#include <iostream>
using namespace std;

int main(){
	int n, k, ans = 0;
	cin >> n;
	while(n--){
		cin >> k;
		ans = max(ans ,k);
	}
	cout << ans << endl;
	return  0;
}
