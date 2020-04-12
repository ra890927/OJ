#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
		if(!a && !b && !c){
			cout << "AND" << endl;
			cout << "OR" << endl;
			cout << "XOR" << endl;
		}
		else if(a != 0 && b == 0 && c == 0 || a == 0 && b != 0 && c == 0)
			cout << "AND" << endl;
		else if(a == 0 && b != 0 && c != 0 || a != 0 && b == 0 && c != 0)
			cout << "OR\n" << "XOR\n";
		else if(a != 0 && b != 0 && c == 0)
			cout << "XOR" << endl;
		else if(a != 0 && b != 0 && c != 0)
			cout << "AND\n" << "OR\n";
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
