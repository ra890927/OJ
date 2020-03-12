#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

struct Test{
	int ans, plm;
};

int N, K;
Test t[MAX_N];
double temp[MAX_N];

bool check(double x){
	double sum = 0.0;

	for(int i = 0; i < N; i++)
		temp[i] = t[i].ans - t[i].plm * x;

	sort(temp , temp + N);

	for(int i = 0; i < N - K; i++)
		sum += temp[N - i - 1];

	return sum >= 0;
}

int main(){
	while(cin >> N >> K){
		if(!N && !K) break;

		for(int i = 0; i < N; i++)
			cin >> t[i].ans;
		for(int i = 0; i < N; i++)
			cin >> t[i].plm;

		double lb = 0.0, ub = 1.0, mid;
		for(int i = 0; i < 100; i++){
			mid = (lb + ub) / 2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}

		lb *= 100;

		printf("%.0lf\n", lb);
	}

	return 0;
}