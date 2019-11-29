#include <iostream>
using namespace std;

int main(){
	long long N, k;
	int m;
	cin >> N >> m;
	while(m--){
		cin >> k;
		if(k%2 == 1) cout << (k + 1) / 2 <<endl;
		else{
			while(k%2 == 0) k += N - (k / 2);
			cout << (k + 1) / 2 <<endl;
		}
	}
}  
