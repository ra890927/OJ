#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		double m, p, ans;
		cin >> m >> p;
		ans = (p - m) / m * 100;
		if(ans > 0) ans += 0.00001;
		else if(ans < 0) ans -= 0.00001;
		
		if(ans >= 10.00 || ans <= -7.00){
			printf("%.2f", ans);
			cout << "% dispose" << endl;
		}
			
		else
			printf("%.2f% keep\n", ans);
	}
	return 0;
} 
