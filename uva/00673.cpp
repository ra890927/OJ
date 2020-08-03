#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string s;
	cin >> T >> ws;

	while(T--){
		getline(cin, s);
		bool check = true;
		vector<char> vec;

		for(int i = 0; i < s.length(); i++){
			if(s[i] == '[' || s[i] == '(') vec.push_back(s[i]);
			else if(s[i] == ']'){
				if(vec.empty() || vec.back() != '['){
					check = false;
					break;
				}
				else vec.pop_back();
			}
			else if(s[i] == ')'){
				if(vec.empty() || vec.back() != '('){
					check = false;
					break;
				}
				else vec.pop_back();
			}
			else{
				check = false;
				break;
			}
		}

		if(vec.empty() && check) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}