#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define INF 1e9
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		string s;
		vector<int> v;
		int init = 0, res = 0, ans = INF;

		getline(cin, s);
		for(int i = 0; i < s.length(); i++){
			if(s[i] != ' '){
				init = 10 * init + (s[i] - '0');
				v.push_back(s[i] - '0');
			}
		}
		res = init;

		while(res != init){
			int num = 0;

			for(int i = 0; i < v.size() / 2; i++){
				num = 10 * num + (res % 10);
				res /= 10;
			}

			ans = min(ans, abs(num - res));
			next_permutation(v.begin(), v.end());
			res = 0;

			for(int &k : v) res = 10 * res + k;
		}

		cout << ans << endl;
	}

	return 0;
}