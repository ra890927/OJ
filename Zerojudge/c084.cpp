#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int p, q;
	while(cin >> p >> q){
		if(!p && !q) break;
		cout <<".";
		int i = 1, d[1000];
		memset(d, 0, sizeof(d));
		d[p] = i;
		while(1){
			p *= 10;
			cout << p / q;
			p %= q;
			i++;
			if(d[p%q] > 0){
				cout<<"\n"<<"The last "<< i - d[p] <<" digits repeat forever."<<endl;
				break;
			}
			else if(p == 0){
				cout<<"\n"<<"This expansion terminates."<<endl;
				break;
			}
			else d[p] = i;
			if(i == 50) cout << "\n";
		}
	}
	return 0;
}
