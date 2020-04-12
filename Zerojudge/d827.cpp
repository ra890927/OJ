#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N)
		cout << N / 12 * 50 + N % 12 * 5 << endl;
	return 0;
	
}