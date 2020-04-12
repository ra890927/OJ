#include <iostream>
using namespace std;

int main(){
	int N, t;
	while(cin >> N){
		for(int i = 0; i < N; i++)
			cin >> t;
		for(int i = 1; i <= N; i++)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}