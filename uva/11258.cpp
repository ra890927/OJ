#include <bits/stdc++.h>
#include <stdint.h>
#define MAX_L 200 + 10
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		string s;
		int64_t dp[MAX_L] = {0};
		
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '0')
				dp[i + 1] = max(dp[i + 1], dp[i]);
			else{
				int64_t temp = 0;
				for(int j = i; j < s.length(); j++){
					temp = 10 * temp + int(s[j] - '0');
					if(temp > INT_MAX) break;
					dp[j + 1] = max(dp[j + 1], dp[i] + temp);
					//cout << j << ": " << dp[j + 1] << endl;
				}
			}
		}
		cout << dp[s.length()] << endl;
	}
	return 0;
}