#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	double k;
	while(cin >> k)
		printf("%.3f\n", (k - 32) * 5 / 9);
	return 0;
} 
