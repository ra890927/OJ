#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		int sum = 0;
		for(int i = 1; i <= N; i++){
			int k;
			cin >> k;
			sum += k * i;
		}
		cout << sum << endl;
	}
	return 0;
} 
