#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int h, k, p, q;
	while(cin >> h >> k >> p >> q){
		int a, b, c, d, res;
		a = (p - h) * (p - h);
		b = q - k;
		c = -2 * h * b;
		d = b * h * h + k * a;
		res = __gcd(a, b), res = __gcd(res, c), res = __gcd(res, d);
		cout << a/res << "y = " << b/res << "x^2 + " << c/res << "x + " << d/res << endl;
	}
	return 0;
}