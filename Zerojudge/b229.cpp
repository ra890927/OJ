#include <iostream>
using namespace std;

int main(){
	int k;
	string s = "16616132878186749607";
	unsigned long long U[51], L[51];
	U[0] = L[0] = 1;
	for(int i = 1; i < 50; i++){
		U[i] = U[i-1] + 2*L[i-1];
		L[i] = U[i-1] + L[i-1];
	}
	while(cin >> k)
		if(k == 50) cout << s << endl;
		else cout << U[k] << endl;
	return 0;
}
