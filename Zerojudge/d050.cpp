#include <iostream>
using namespace std;

int main(){
	int k;
	while(cin >> k)
		cout << (k + 9) % 24 << endl;
	return 0;
} 
