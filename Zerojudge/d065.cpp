#include <iostream>
using namespace std;

int main(){
	int k, ans = 0;
	for(int i = 0; i < 3; i++){
		cin >> k;
		ans = max(ans, k);
	}
	cout << ans << endl;
	return 0;
}
