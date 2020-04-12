#include <iostream>
using namespace std;

int main(){
	int n;
	int a = 1, b = 1, c = a + b;
	cin >> n;
	cout<<"O";
	for(int i = 2; i <= n; i++){
		if(i == c){
			cout<<"O";
			a = b;
			b = c;
			c = a + b;
		}
		else cout<<"o";
	}
	cout<<endl;
	return 0;
}
