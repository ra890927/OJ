#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50000
using namespace std;

int N, K;
int p[MAXN];

bool bs(int r){
	int cnt = 0;
	int s = -1;
	for(int i = 0; i < N; i++)
		if(p[i] > s) cnt++, s = p[i] + r;
	return cnt <= K;
}

int main(){
	while(cin >> N >> K){
		memset(p, 0, sizeof(p));
		for(int i = 0; i < N; i++)
			cin >> p[i];
		sort(p, p + N);
		int ub = p[N-1] - p[0], lb = 0, mid;
		while(ub - lb > 1){
			mid = (ub + lb) / 2;
			if(bs(mid)) ub = mid;
			else lb = mid;
		}
		cout << ub << endl;
	}
	return 0;
}
