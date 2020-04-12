#include <iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		if(s[0] == '-'){
			string ans;
			if(int(s[5] - '0') >= 5){
				s[4]++;
				if(int(s[4] - '0') == 10)
					s[3]++, s[4] = '0';
				if(int(s[3] - '0') == 10)
					s[1]++, s[3] = '0';
			}
			for(int i = 0; i < 5; i++){
				if(i >= s.length()) ans += '0';
				else ans = ans + s[i];
			}
			if(ans == "-0.00") cout << "0.00" << endl;
			else cout << ans << endl;
		}
		else{
			string ans;
			if(int(s[4] - '0') >= 5){
				s[3]++;
				if(int(s[3] - '0') == 10)
					s[2]++, s[3] = '0';
				if(int(s[2] - '0') == 10)
					s[0]++, s[2] = '0';
			}
			for(int i = 0; i < 4; i++){
				if(i >= s.length()) ans += '0';
				else ans = ans + s[i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}