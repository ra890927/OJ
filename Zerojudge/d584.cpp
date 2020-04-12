#include <iostream>
using namespace std;

int main(){
	int k, lv;
	while(cin >> k >> lv){
		if(k == 0) cout << "0" << endl;
		else{
			int ans = 1;
			if(k == 2)
				ans += 3 * (lv - 8);
			else
				ans += 3 * (lv - 10);
			ans += (lv >= 30) + (lv >= 70) + 3 * (lv >= 120);
			cout << ans << endl;
		}
	}
	return 0;
}