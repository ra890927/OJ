#include <iostream>
using namespace std;
typedef struct{
	int t[3][3];
}Matrix;
const int mod = 10007;
Matrix in, I3, o, init;
Matrix mult(Matrix a, Matrix b){
	Matrix t = o;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++){
				t.t[i][k] += a.t[i][j] * b.t[j][k] % mod;
				t.t[i][k] %= mod;
			}
	
	return t;
}

void ans(int n){
	Matrix x =  init, y = in;
	while(n){
		if(n & 1) x = mult(x, y);
		y = mult(y, y);
		n /= 2;
	}
	cout << x.t[0][0] << endl;
}

int main(){
	int n;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			in.t[i][j] = 0, I3.t[i][j] = 0,
			o.t[i][j] = 0, init.t[i][j] = 0;
	for(int i = 0; i < 3; i++) I3.t[i][i] = 1;
	init.t[0][0] = 5;
	init.t[1][0] = init.t[0][1] = 3;
	init.t[0][2] = init.t[1][1] = init.t[1][2] = 1;
	init.t[2][0] = init.t[2][1] = init.t[2][2] = 1;
	in.t[0][0] = in.t[0][1] = 1;
	in.t[1][0] = in.t[1][2] = 1;
	in.t[2][0] = 1;
	while(cin >> n){
		if(n <= 3) cout << "1" << endl;
		else if(n == 4) cout << "3" << endl;
		else ans(n - 5);
	}
	return 0;
}