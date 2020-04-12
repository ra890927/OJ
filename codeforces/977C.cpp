#include <iostream>
#include <algorithm>
#define MAXN 200000
#define INF 1e9 + 1
using namespace std;

int main(){
	int N, k;
	int a[MAXN];
	cin >> N >> k;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	a[N] = INF;
	if(k == 0){
		if(a[0] != 1) cout << a[0] - 1 <<endl;
		else cout << "-1" <<endl;
	}
	else if(a[k - 1] >= a[k]) cout << "-1" <<endl;
	else cout << a[k - 1] <<endl;
}
