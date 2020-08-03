#include <cstdio>
#include <iostream>
using namespace std;

int N;
double A, B;

const double m = 1e-6;

bool check(double y){
	double z, x = A;

	for(int i = 0; i < N - 2; i++){
		z = 2 * y - x + 2;

		if(z < 0 + m) return false;

		x = y;
		y = z;
	}

	B = z;

	return true;
}

int main(){
<<<<<<< HEAD
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B;
=======
	cin >> N >> A;
>>>>>>> 04afab757e82de420dc433788c5a8ac7d350c154

	double lb = 0.0, ub = A, mid;

	for(int i = 0; i < 100; i++){
		mid = (lb + ub) / 2;

		if(check(mid)) ub = mid;
		else lb = mid;
	}

	printf("%.2lf\n", B);

	return 0;
}