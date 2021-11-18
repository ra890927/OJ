#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

int main(){
	int64_t L, R;
	while(cin >> L >> R){
		if(!L && !R) break;

		cout << R / 5 - L / 5 + 1 << endl;
	}

	return 0;
}