#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		if(!N) break;
		for(int i = N; i > 0; i--){
			for(int j = 1; j <= N; j++){
				if(j >= i)
					cout << "+";
				else
					cout << "_";
			}
			cout << endl;
		}
	}
	return 0;
}