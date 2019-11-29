#include <iostream>
using namespace std;

int a[8], b[4];

int main(){
	int N;
	for(int i = 0; i < 8; i++)
		cin >> a[i];
	cin >> N; 
	while(N--){
		int p, q, r;
		string s;
		cin >> s;
		if(s == "LOAD"){
			cin >> p >> q;
			b[p] = a[q];
		}
		else if(s == "STORE"){
			cin >> p >> q;
			a[p] = b[q];
		}
		else if(s == "ADD"){
			cin >> p >> q >> r;
			b[p] = b[q] + b[r];
		}
		else if(s == "MOVE"){
			cin >> p >> q;
			b[p] = b[q];
		}
	}
	cout << b[0] << endl << a[0] << endl;
	return 0;
}
