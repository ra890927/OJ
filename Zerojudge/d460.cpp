#include <iostream>
using namespace std;

int main(){
	int k;
	while(cin >> k){
		if(k >= 0 && k < 6) cout << "0" << endl;
		else if(k >= 6 && k < 12) cout << "590" << endl;
		else if(k >= 12 && k < 18) cout << "790" << endl;
		else if(k >= 18 && k < 60) cout << "890" << endl;
		else cout << "399" << endl;
	}
	return 0;
}