#include <iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		int sum = 0;
		bool res = false;
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= 'a' && s[i] <= 'z')
				sum += int(s[i] - 'a') + 1;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				sum += int(s[i] - 'A') + 1;
			else
				res = true;
		}
		if(!sum && s.length() == 1) break;
		
		if(res) cout << "Fail" << endl;
		else cout << sum << endl;
	}
	return 0;
} 
