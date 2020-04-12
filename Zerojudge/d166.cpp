#include <iostream>
#include <sstream>
#include <vector>
#define MAXN 51
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		if(s == "-1") break;
		int num[MAXN];
		vector<int> v;
		stringstream ss;
		ss << s;
		int i = 1, k;
		while(ss >> k) num[i++] = k;
		
		for(i -= 1; i > 0 ; i--){
			if(num[i]) v.insert(v.begin() + num[i], i);
			else v.insert(v.begin(), i);
		}
		
		for(i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
}