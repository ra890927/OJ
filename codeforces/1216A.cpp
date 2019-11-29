#include <iostream>
using namespace std;

int main(){
	int N, cnt  = 0;
	string s;
	cin >> N >> s;
	for(int i = 0; i < N; i += 2){
		if(s[i] == s[i+1]){
			if(s[i] == 'a') s[i] = 'b';
			else s[i] = 'a';
			cnt++;
		}
	}
	cout << cnt << endl << s << endl;
	return 0;
}