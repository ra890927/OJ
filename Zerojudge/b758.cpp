#include <iostream>
using namespace std;

int main(){
	int n, m;
	while(cin >> n >> m){
		n += 2;
		m += 30;
		if(m >= 60){
			n += m / 60;
			m %= 60;
		}
		n %= 24;
		if(n < 10){
			cout << "0" << n << ":";
			if(m == 0) cout << "00" << endl;
			else cout << m << endl;
		}
		else{
			cout << n << ":" ;
			if(m == 0) cout << "00" << endl;
			else cout << m << endl;
		}
	}
	return 0;
}