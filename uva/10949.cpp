#include <bits/stdc++.h>
#define MAX_H 20 + 1
#define MAX_N 20000 + 1
#define INF 1e9;
using namespace std;

string m[MAX_H];

string transfer(){
	char c;
	string ret;
	int N, p, q;

	cin >> N >> p >> q;
	ret += m[--p][--q];

	while(N--){
		cin >> c;
		switch(c){
			case 'N':
				p--;
				break;
			case 'S':
				p++;
				break;
			case 'W':
				q--;
				break;
			case 'E':
				q++;
		}

		ret += m[p][q];
	}

	return ret;
}

int solve(string a, string b){
	vector<int> temp[128];
	for(int i = 0; i < a.length(); i++)
		temp[a[i]].push_back(i);

	vector<int> lis;
	lis.push_back(-1);

	for(int i = 0; i < b.length(); i++){
		int k = b[i];
		for(int j = temp[k].size() - 1; j >= 0; j--){
			if(temp[k][j] > lis.back()) lis.push_back(temp[k][j]);
			else *lower_bound(lis.begin(), lis.end(), temp[k][j]) = temp[k][j];
		}
	}

	return lis.size() - 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for(int k = 0; k < T; k++){
		int H, W, ans;
		cin >> H >> W;
		for(int i = 0; i < H; i++)
			cin >> m[i];

		string a = transfer();
		string b = transfer();

		if(a.length() > b.length()) ans = solve(a, b);
		else ans = solve(b, a);

		cout << "Case " << k + 1 << ": " << a.length() - ans << " " << b.length() - ans << '\n';
	}

	return 0;
}