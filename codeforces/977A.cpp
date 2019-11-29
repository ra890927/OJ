#include <iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		int res = n % 10;
		if(res == 0) n /= 10;
		else n--;
	}
	cout << n <<endl;
}
