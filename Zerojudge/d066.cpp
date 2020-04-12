#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b)
		if(a > 7 && a < 17)
			cout << "At School" << endl;
		else if(a == 7 && b >= 30)
			cout << "At School" << endl;
		else
			cout << "Off School" << endl; 
	return 0;
}
