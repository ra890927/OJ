#include <bits/stdc++.h>
using namespace std;

void discretize(int *lb, int *rb){
	int cp[10], len = rb - lb, sz;
	
	memcpy(cp, lb, len * sizeof(int));
	sort(cp, cp + len);
	sz = unique(cp, cp + len) - cp;
	for(int i = 0; i < len; i++)
		*(lb + i) = lower_bound(cp, cp + sz, *(lb + i)) - cp;
	return;
}

int main(){
	int x[6], y[6];
	for(int i = 0; i < 6; i++)
		cin >> x[i] >> y[i];
	
	discretize(x, x + 6);
	discretize(y, y + 6);
	
	bool mp[10][10] = {}, res = false;
	for(int i = x[0]; i < x[1]; i++)
		for(int j = y[0]; j < y[1]; j++)
			mp[i][j] = true;
		
	for(int i = x[2]; i < x[3]; i++)
		for(int j = y[2]; j < y[3]; j++)
			mp[i][j] = false;
		
	for(int i = x[4]; i < x[5]; i++)
		for(int j = y[4]; j < y[5]; j++)
			mp[i][j] = false;
		
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(mp[i][j]){
				res = true;
				break;
			}
		}
	}
	
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}