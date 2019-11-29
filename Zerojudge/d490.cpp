#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int sum = 0;
		for(int i = a; i <= b; i++)
			if(!(i % 2)) sum += i;
		cout << sum << endl;
	}
	return 0;
}