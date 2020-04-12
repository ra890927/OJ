#include <iostream>
#include <cstring>
#define MAXN 500
using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M){
		int x[2], y[2], X, Y;
		bool map[MAXN][MAXN];
		memset(map, 0, sizeof(map));
		
		cin >> x[0] >> y[0];
		for(int i = 1; i < M; i++){
			cin >> x[i%2] >> y[i%2];
			
			if(x[i%2] == x[(i-1)%2]){
				X = x[i%2];
				for(int j = min(y[i%2], y[(i-1)%2]); j <= max(y[i%2], y[(i-1)%2]); j++)
					map[X-1][j-1] = true;
			}
			else{
				Y = y[i%2];
				
				for(int j = min(x[i%2], x[(i-1)%2]); j <= max(x[i%2], x[(i-1)%2]); j++)
					map[j-1][Y-1] = true;
			}
		}
		
		for(int i = 0; i < N + 2; i++) cout << "-";
		cout << endl;
		for(int i = 0; i < N; i++){
			cout << "|";
			for(int j = 0; j < N; j++){
				if(map[i][j]) cout << "*";
				else cout << " ";
			}
			cout << "|" << endl;
		}
		for(int i = 0; i < N + 2; i++) cout << "-";
		cout << endl;
	}
	return 0;
}
