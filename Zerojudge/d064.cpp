#include <iostream>
using namespace std;

int main(){
	int k;
	while(cin >> k)
		if(k % 2) cout << "Odd" << endl;
		else cout << "Even" << endl;
	return 0;
}
