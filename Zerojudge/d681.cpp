#include <iostream>
#include <sstream>
using namespace std;

int main(){
	string s, k, res, ans;
	while(getline(cin, s)){
		stringstream ss;
		ss << s;
		ss >> ans;
		cout << ans;
		while(ss >> k){
			if(k == "or"){
				cout << "||";
				ss >> k;
				cout << k;
				for(int i = 0; i < 5; i++)
					ans[i] |= k[i];
			}
			else{
				cout << "&&";
				ss >> k;
				cout << k;
				for(int i = 0; i < 5; i++)
					ans[i] &= k[i];
			}
		}
		cout << " = " << ans << endl;
	}
	return 0;
}