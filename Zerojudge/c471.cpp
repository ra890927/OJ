#include <iostream>
#include <algorithm>
#define MAXN 100000
using namespace std;

struct Data{
	long long w, f;
}d[MAXN];

bool cmp(Data &a, Data &b){
	return a.w * b.f < b.w * a.f;
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> d[i].w;
	for(int i = 0; i < N; i++) cin >> d[i].f;
	sort(d, d + N, cmp);
	long long sum = 0, res = 0;
	for(int i = 0; i < N; i++){
		res += sum * d[i].f;
		sum += d[i].w;
	}
	cout << res <<endl;
	return 0;
}
