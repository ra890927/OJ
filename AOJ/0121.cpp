#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

queue<string> q;
map<string, int> m;
const int d[] = {1, -1, 4, -4};

void solve(){
	m["01234567"] = 1;
	q.push("01234567");
	while(!q.empty()){
		int t = 0;
		string res = q.front();
		q.pop();
		for(int i = 0; i < res.length(); i++)
			if(res[i] == '0') t = i;
		for(int i = 0; i < 4; i++){
			if(0 <= t + d[i] && t + d[i] < 8 &&
            !(t == 3 && i == 0) && !(t == 4 && i == 1)){
            	string u = res;
            	swap(u[t], u[t + d[i]]);
            	if(m[u] == 0){
            		q.push(u);
            		m[u] = m[res] + 1;
				}
			}
		}
	}	
}
int main(){
	solve();
	while(1){
		int k;
		string s;
		for(int i = 0 ;i < 8; i++){
			if(!(cin >> k)) return 0;
			s = s + char(k + '0');
		}
		cout << m[s] - 1 << endl;
	}
	return 0;
}
