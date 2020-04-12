#include <iostream>
using namespace std;

int main(){
	int N, M, T;
	cin >> T;
	while(T--){
		int m[12][12];
		cin >> N >> M;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				cin >> m[i][j];
				
		bool res = true;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(m[i][j] != m[N-i+1][M-j+1])
					res = false;
			}
		}
		if(res) cout << "go forward" << endl;
		else cout << "keep defending" << endl;
	}
	return 0;
}
