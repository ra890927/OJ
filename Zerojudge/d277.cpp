#include <iostream>
using namespace std;

int main(){
	int k;
	while(cin >> k){
		if(k & 1) cout << k - 1 << endl;
		else cout << k << endl;
	}
	return 0;
}