#include <iostream>
#include <cmath>
using namespace std;

int gcd(int p, int q){
	int temp;
	while(q)
		temp = q, q = p % q, p = temp;
	return p;
}

int main(){
	char op;
	int a, b, c, d;
	while(cin >> a >> b >> c >> d >> op){
		if(op == '+'){
			int p = a * d + b * c;
			int q = b * d;
			int gc = gcd(p, q);
			p /= gc;
			q /= gc;
			if(p * q > 0)
				p = abs(p), q = abs(q);
			else if(p > 0 && q < 0)
				p = -p, q = -q;
			if(p == 0) cout << "0" << endl;
			else if(q == 1) cout << p << endl;
			else cout << p << "/" << q << endl;
		}
		else if(op == '-'){
			int p = a * d - b * c;
			int q = b * d;
			int gc = gcd(p, q);
			p /= gc;
			q /= gc;
			if(p * q > 0)
				p = abs(p), q = abs(q);
			else if(p > 0 && q < 0)
				p = -p, q = -q;
			if(p == 0) cout << "0" << endl;
			else if(q == 1) cout << p << endl;
			else cout << p << "/" << q << endl;
		}
		else if(op == '*'){
			int p = a * c;
			int q = b * d;
			int gc = gcd(p, q);
			p /= gc;
			q /= gc;
			if(p * q > 0)
				p = abs(p), q = abs(q);
			else if(p > 0 && q < 0)
				p = -p, q = -q;
			if(p == 0) cout << "0" << endl;
			else if(q == 1) cout << p << endl;
			else cout << p << "/" << q << endl;
		}
		else{
			int p = a * d;
			int q = b * c;
			int gc = gcd(p, q);
			p /= gc;
			q /= gc;
			if(p * q > 0)
				p = abs(p), q = abs(q);
			else if(p > 0 && q < 0)
				p = -p, q = -q;
			if(p == 0) cout << "0" << endl;
			else if(q == 1) cout << p << endl;
			else cout << p << "/" << q << endl;
		}
	}
	return 0;
}