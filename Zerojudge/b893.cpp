#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int a[6];
	bool res1 = true;
	for(int i = 0; i < 6; i++){
		cin >> a[i];
		if(a[i]) res1 = false;
	}
	
	int k = 0, s = -36;
	long long ans[73];
	while(s < 36){
		long res = a[0];
		for(int j = 1; j < 6; j++)
			res = res * s + a[j];
		ans[k] = res;
		k++;
		s++;
	}
	
	if(res1) cout << "Too many... = =\"" << endl;
	else{
		bool ot = true;
		for(int i = 1; i < 72; i++){
			if((ans[i-1] > 0 && ans[i] < 0) || (ans[i-1] < 0 && ans[i] > 0)){
				ot = false;
				cout << i-1-36 <<" "<< i - 36 << endl;
			}
			if(ans[i] == 0){
				ot = false;
				cout << i - 36 <<" "<< i - 36 << endl; 
			}
		}
		if(ot) cout << "N0THING! >\\\\\\<" << endl;
	}
	return 0;
}
