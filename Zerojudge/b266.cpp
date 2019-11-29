// 矩陣平面變換 旋轉+翻轉 
// NA 80% 

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int R, C, M;
struct Array{
	int v, x, y;
}a[MAXN];
const int t[4] = {0, 1, -1, 0};
const int c[4] = {1, 0, 0, -1};

void change(){
	for(int i = 0; i < R * C; i++){
		int k = a[i].x;
		a[i].x = (c[0] * a[i].x) + (c[1] * a[i].y);
		a[i].y = (c[2] * k) + (c[3] * a[i].y);
	}
}
void turn(){
	swap(R, C);
	for(int i = 0; i < R * C; i++){
		int k = a[i].x;
		a[i].x = (t[0] * a[i].x) + (t[1] * a[i].y);
		a[i].y = (t[2] * k) + (t[3] * a[i].y);
	}
}
bool cmp(Array &a, Array &b){
	if(a.y == b.y) return a.x < b.x;
	else return a.y > b.y;
}

int main(){
	while(cin >> R >> C >> M){
		memset(a, 0, sizeof(a));
		int k, n = 0, p = 0, q = 0;
		for(int i = R; i > 0; i--){
			for(int j = 1; j <= C; j++){
				cin >> a[n].v;
				a[n].x = j;
				a[n].y = i;
				n++;
			}
		}
		while(M--){
			cin >> k;
			if(k) change();
			else turn();
		}
		sort(a, a + R * C, cmp);
		cout << R <<" "<< C << endl;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cout << a[C * i + j].v <<" ";
			}
			cout << endl;
		}
	}
	return 0;
}
