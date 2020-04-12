#include <iostream>
using namespace std;

int main(){
	int N, k = 1;
	string s, ans;
	cin >> N >> s;
	for(int i = 1; i < N; i++){
		if(s[i-1] == s[i]) k++;
		if(s[i-1] != s[i] || i == N-1){
			string res;
			while(k){
				res = char(k % 10 + '0') + res;
				k /= 10;
			}
			ans += res;
			ans += s[i-1];
			k++;
		}
	}
	if(s[N-1] != s[N-2]){
		ans += '1';
		ans += s[N-1];
	}
	if(ans.length() >= N) cout << s << endl;
	else cout << ans << endl;
	return 0;
}