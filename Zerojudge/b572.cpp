#include <iostream>
using namespace std;

int main(){
	int K;
	cin >> K;
	while(K--){
		int H1, M1, H2, M2, m;
		cin >> H1 >> M1 >> H2 >> M2 >> m;
		M1 += m;
		if(M1 >= 60){
			int k = M1 / 60;
			M1 %= 60;
			H1 += k;
		} 
		if(H1 <= H2){
			if(M1 <= M2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}
