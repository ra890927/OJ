#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	string s, t;
	stringstream ss;
	vector<int> v;
	while(getline(cin, t)){
		ss << t;
		while(ss >> s){
			if(s[0] != '+' && s[0] != '-' && s[0] != '*' && s[0] != '/' && s[0] != '%'){
				int k;
				stringstream ss1;
				ss1 << s;
				ss1 >> k;
				v.push_back(k);
			}
			else{
				char op = s[0];
				int b = v.back();
				v.pop_back();
				int a = v.back();
				v.pop_back();
				switch(op){
					case '+':
						v.push_back(a + b);
						break;
					case '-':
						v.push_back(a - b);
						break;
					case '*':
						v.push_back(a * b);
						break;
					case '/':
						v.push_back(a / b);
						break;
					case '%':
						v.push_back(a % b);
						break;
				}
			}
		}
		cout << v.back() << endl;
		v.clear();
		ss.str("");
		ss.clear();
	}
	return 0;
} 
