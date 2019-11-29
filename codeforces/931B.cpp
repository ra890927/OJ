#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int k = 0, n, a, b;
	cin >> n >> a >> b;
	a--;
	b--;
	while(a != b){
		a /= 2;
		b /= 2;
		k++;
	}
	if(pow(2, k) >= n) cout<<"Final!"<<endl;
	else cout << k << endl;
} 
