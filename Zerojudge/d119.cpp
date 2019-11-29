#include <iostream>
#include <sstream>
#define MAXN 50000 + 1
using namespace std;

int k, sum;
int coin[10] = {1,5,10,20,50,100,200,500,1000,2000};
long long int dp[MAXN];

void solve(){
	dp[0] = 1;
	for(int i = 0; i < 10; i++){
		for(int j = coin[i]; j < MAXN; j++){
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
}

int main(){
	solve();
	string s;
	while(getline(cin, s)){
		stringstream ss;
		ss << s;
		sum = 0;
		while(ss >> k) sum += k;
		if(!sum) break;
		else cout << dp[sum] - 1 << endl;
	}
} 
