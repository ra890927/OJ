#include <iostream>
#include <algorithm>
#define MAXN 1000 + 1
using namespace std;

struct Can{
	int dur, num;
};

bool cmp(Can &a,  Can &b){
	if(a.dur == b.dur) return a.num < b.num;
	return a.dur > b.dur;
}

int main(){
	int N;
	while(cin >> N){
		Can c[MAXN];
		for(int i = 0; i < N; i++){
			cin >> c[i].dur;
			c[i].num = i + 1;
		}
		sort(c, c + N, cmp);
		
		int res = c[0].dur, sum = 0;
		for(int i = 0; i < N; i++)
			sum += c[i].dur * i + 1;
		
		cout << sum << endl;
		for(int i = 0; i < N; i++)
			cout << c[i].num << " ";
		cout << endl;
	}
	return 0;
}