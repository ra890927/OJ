#include <iostream>
#define MAXN 20 + 1
using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M){
		string p, q;
		string arr[MAXN][2];
		for(int i = 0; i < N; i++)
			cin >> arr[i][0] >> arr[i][1]; 
			
		while(M--){
			cin >> p >> q;
			if(p == "brand"){
				for(int i = 0; i < N; i++)
					if(q == arr[i][0])
						cout << arr[i][0] << " " << arr[i][1] << endl;
			}
			
			else if(p == "color"){
				for(int i = 0; i < N; i++)
					if(q == arr[i][1])
						cout << arr[i][0] << " " << arr[i][1] << endl;
			}
		}
	}
	return 0;
}