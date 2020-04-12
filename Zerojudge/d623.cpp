#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double a, b, c, d;
	while(cin >> a >> b >> c >> d){
		if(!a && !b && !c && !d) break;
		double res = a * d - b * c;
		if(!res) cout << "cheat!" << endl;
		else{
			printf("%.5f %.5f\n", d / res, -b / res);
			printf("%.5f %.5f\n", -c / res, a / res);
		}
	}
	return 0;
}