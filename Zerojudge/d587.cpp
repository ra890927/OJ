#include <iostream>
using namespace std;

int main(){
	int N, k, n1  = 0, n2 = 0, n3  = 0;
	cin >> N;
	while(N--){
		cin >> k;
		if(k == 1) n1++;
		if(k == 2) n2++;
		if(k == 3) n3++;
	}
	while(n1--) cout << "1 ";
	while(n2--) cout << "2 ";
	while(n3--) cout << "3 ";
	cout << endl;
	return 0;
}