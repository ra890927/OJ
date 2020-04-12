#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int main(){
	int k;
	while(cin >> k) mp[k]++;
	
	for(auto it: mp){
		if(it.second % 3){
			cout << it.first << endl;
			break;
		}
	}
	return 0;
}