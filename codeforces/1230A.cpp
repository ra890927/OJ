#include <bits/stdc++.h>
using namespace std;

int main(){
	int m[4], sum = 0;
	for(int i = 0; i < 4; i++){
		cin >> m[i];
		sum += m[i];
	}
	sort(m, m + 4);
	
	bool res = false;
	if(m[0] + m[3] == m[1] + m[2]) res = true;
	
	for(int i = 0; i < 4; i++)
		if(sum - m[i] == m[i]) res = true;
	
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}