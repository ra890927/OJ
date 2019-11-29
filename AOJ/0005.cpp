#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int p = a, q = b, r;
		while(q)
			r = p % q, p = q, q = r;
		cout << p << " " << a / p * b / p * p << endl; 
	}
	return 0;
}
