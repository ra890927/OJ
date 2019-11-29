#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int sum = 0;
		for(int i = a; i <= b; i++)
			sum += ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0));
		cout << sum << endl;
	}
	return 0;
}