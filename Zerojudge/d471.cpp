#include <iostream>
using namespace std;

int n, bits[16];

void dfs(int l){
	if(l == n){
		for(int i = 0; i < n; ++i)
			cout << bits[i];
		cout << endl;
		return;
	}
	
	bits[l] = 0;
	dfs(l + 1);
	
	bits[l] = 1;
	dfs(l + 1);
}

int main(){
	while(cin >> n)
		dfs(0);
	return 0;
}