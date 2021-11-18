#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b){
	int64_t temp;
	while(b)
		temp = a % b, a = b, b = temp;
	return a;
}

int main(){
	int index = 1;
	int64_t v1, d1, v2, d2;
	while(cin >> v1 >> d1 >> v2 >> d2){
		if(!(v1 + d1 + v2 + d2)) break;
		cout << "Case #" << index++ << ": ";
		if(d1 * v2 < d2 * v1)
			cout << "You owe me a beer!" << endl;
		else
			cout << "No beer for the captain." << endl;

		if((d1 * v2 + d2 * v1) % (v1 * v2 * 2) == 0){
			cout << "Avg. arrival time: " << (d1 * v2 + d2 * v1) / (v1 * v2 * 2) << endl;
		}
		else{
			int64_t _gcd = gcd(d1 * v2 + d2 * v1, v1 * v2 * 2);
			cout << "Avg. arrival time: " << (d1 * v2 + d2 * v1) / _gcd << "/" << (v1 * v2 * 2) / _gcd << endl;
		}
	}
	return 0;
}