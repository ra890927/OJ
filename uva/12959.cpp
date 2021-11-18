#include <bits/stdc++.h>
#define MAX_N 500 + 1
using namespace std;

int main(){
	int J, R;
	while(cin >> J >> R){
		if(!J && !R) break;
		int winner = 0;
		int player[MAX_N] = {0};
		while(R--){
			int temp = 0;
			for(int i = 0; i < J; i++){
				cin >> temp;
				player[i] += temp;
				if(player[i] >= player[winner])
					winner = i;
			}
		}
		cout << winner + 1 << endl;
	}
	return 0;
}