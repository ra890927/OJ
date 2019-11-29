#include <iostream>
using namespace std;

int main(){
	int a, b, c, sum = 0, e = 5;
	while(e--){
		cin >> a >> b >> c;
		if(a + b > c && b + c > a && a + c > b) sum++;
	}
	cout << sum << endl;
	return 0;
}