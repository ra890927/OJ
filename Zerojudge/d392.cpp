#include <iostream>
#include <sstream>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		long long int k, sum = 0;
		stringstream ss;
		ss << s;
		while(ss >> k) sum += k;
		cout << sum << endl;
	}
	return 0;
}