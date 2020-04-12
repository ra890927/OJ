#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b)
		cout << (b - a) / 2 +(!(a % 2) || !(b % 2)) << endl;
	return 0;
}