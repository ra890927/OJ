#include <iostream>
#include <cstring>
using namespace std;

int c[26][26];
int main(){
	int n, res = 0, p, q;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n - 1; i++)
		c[s[i] - 'A'][s[i + 1] - 'A']++;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(res < c[i][j]){
				res = c[i][j];
				p = i;
				q = j;
			}
		}
	}
	cout << char(p + 'A') << char(q + 'A') << endl;
}
