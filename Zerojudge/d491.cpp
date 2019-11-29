#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int temp = min(a, b);
		b = max(a, b);
		a = temp;
		int sum = 0;
		for(int i = a; i <= b; i++)
			if(!(i % 2)) sum += i;
		cout << sum << endl;
	}
	return 0;
}