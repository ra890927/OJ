#include <iostream>
#include <algorithm>
#define MAX_N 50000 + 5
using namespace std;

int L, N, M;
int rock[MAX_N];

bool check(int x){
	int cnt = 0, last = 0;
	
	for(int i = 1; i < N + 2; i++){
		if(rock[i] - last >= x)
			last = rock[i];
		else cnt++;
	}
	
	return cnt <= M;
}

int main(){
	cin >> L >> N >> M;
	
	rock[0] = 0, rock[N + 1] = L;
	for(int i = 1; i <= N; i++)
		cin >> rock[i];
	sort(rock, rock + N + 1);
	
	int lb = 1, ub = L, mid;
	
	while(ub - lb > 1){
		mid = (lb + ub) / 2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	
	if(N == 0) cout << L << endl;
	else cout << lb << endl;
	
	return 0;
}