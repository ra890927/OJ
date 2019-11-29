#include <iostream>
#define MAXN 10000
using namespace std;

int N, a[MAXN];

bool res(){
	for(int i = 1; i < N; i++)
		if(a[i] < a[i-1]) return false;
	return true;
}

int main(){
	cin >> N;
	int cnt = 0;
	bool res = true;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	while(res){
		res = false;
		for(int i = 0; i < N-1; i++){
			int tmp = 0;
			if(a[i] > a[i+1]){
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				cnt++;
				res = true;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
