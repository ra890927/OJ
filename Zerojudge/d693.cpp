#include <iostream>
using namespace std;

int gcd(int a, int b){
	int temp;
	while(b)
		temp = b, b = a % b, a = temp;
	return a;
}

int main(){
	int N;
	while(cin >> N){
		if(!N) break;
		long long a = 1, b;
		for(int i = 0; i < N; i++){
			cin >> b;
			a = (a * b) / gcd(a, b);
		}
		cout << a << endl;
	}
	return 0;
}