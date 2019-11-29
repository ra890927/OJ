#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, k;
	string s;
	while(cin >> N >> k >> s){
		if(N > 1){
			if(s[0] != '1' && k > 0){
				s[0] = '1';
				k--;
			}
			for(int i = 1; i < N; i++){
				if(s[i] != '0' && k > 0){
					s[i] = '0';
					k--;
				}
			}
			cout << s << endl;
		}
		else{
			if(k > 0) cout << "0" << endl;
			else cout << s << endl;
		}
	}
	return 0;
}