#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;

int N;
string d[MAXN];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int p, int q){
	if(d[p][q] == '+') return;
	d[p][q] = '+';
	for(int i = 0; i < 4; i++){
		int h = p + dy[i];
		int k = q + dx[i];
		if(h >= 0 && h < N && k >= 0 && k < N)
			dfs(h, k);
	}
}

int main(){
	int p, q;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> d[i];
	cin >> p >> q;
	dfs(p, q);
	for(int i = 0; i < N; i++)
		cout << d[i] << endl;
	return 0; 
}
