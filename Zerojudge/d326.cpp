#include <iostream>
using namespace std;

int main(){
	int k, temp;
	unsigned int n;
	while(cin >> n >> k >> temp){
		int res[32] = {0}, i = 0;
		
		while(n){
			res[i++] = n % 2;
			n /= 2;
		}
		res[k] = temp;
		
		for(int i = 31; i >= 0; i--)
			cout << res[i];
		cout << endl;
	}
	return 0;
}