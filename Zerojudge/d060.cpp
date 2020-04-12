#include <iostream>
using namespace std;

int main(){
	int k;
	while(cin >> k)
		cout << (85 - k) % 60 << endl;
	return 0;
}
