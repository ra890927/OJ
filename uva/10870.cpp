#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll

struct Matrix{
	ll m[16][16];
};

Matrix I;
ll d, n, mod;
ll coef[16], f[16];

Matrix init(){
	Matrix Mat;
	memset(Mat.m, 0, sizeof(Mat.m));

	return Mat;
}

Matrix Mutiple(Matrix a, Matrix b){
	Matrix ret = init();
	for(int x = 0; x < d; x++){
		for(int y = 0; y < d; y++){
			for(int i = 0; i < d; i++)
				ret.m[x][y] = (ret.m[x][y] + (a.m[x][i] * b.m[i][y]) % mod) % mod;
			ret.m[x][y] %= mod;
		}
	}

	return ret;
}

Matrix fast_pow(Matrix base, int n){
	Matrix ans = I;
	while(n){
		if(n & 1)
			ans = Mutiple(ans, base);

		base = Mutiple(base, base);

		n >>= 1;

	}

	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> d >> n >> mod){
		if(!d && !n && !mod) break;

		memset(coef, 0, sizeof(coef));
		memset(f, 0, sizeof(f));

		for(int i = 1; i <= d; i++){
			cin >> coef[i];
			coef[i] %= mod;
		}

		for(int i = 1; i <= d; i++){
			cin >> f[i];
			f[i] %= mod;
		}

		Matrix Base, Ans;

		I = init();
		for(int i = 0; i < d; i++)
			I.m[i][i] = 1;

		memset(Base.m, 0, sizeof(Base.m));
		for(int i = 0; i < d; i++)
			Base.m[0][i] = coef[i + 1];
		for(int i = 1; i < d; i++)
			Base.m[i][i - 1] = 1;


		Ans = fast_pow(Base, n - d);

		ll ans = 0;
		for(int i = 0; i < d; i++)
			ans = (ans + (Ans.m[0][i] * f[d - i]) % mod) % mod;
		cout << ans << endl;
	}
	return 0;
}