#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int K, N;
	cin >> K;
	for(int i = 1; i <= K; i++){
		cin >> N;
		int a, b, sum = 0, res = 3660;
		for(int j = 0; j < N; j++){
			cin >> a >> b;
			sum += 60 * a + b;
			res = min(res, 60 * a + b);
		}
		sum /= N;
		printf("Track %d:\n", i);
		printf("Best Lap: %d minute(s) %d second(s).\n", res / 60, res % 60);
		printf("Average: %d minute(s) %d second(s).\n\n", sum / 60, sum % 60);
	}
	return 0;
}