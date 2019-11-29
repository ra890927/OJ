#include <iostream>
using namespace std;

int main(){
	int N, t;
	int m[50][50];
	cin >> N >> t;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> m[i][j];
	
	int i = N/2+1;
	int j = N/2+1;
	int k = 1, cnt = 0, count = 0;
	while(1){
		for(int s = 0; s < k; s++){
			cout << m[i][j];
			if(t == 0) j--;
			else if(t == 1) i--;
			else if(t == 2) j++;
			else i++;
			count++;
		}
		if(t < 3) t++;
		else t = 0;
		cnt++;
		if(cnt % 2 == 0) k++;
		if(count == N*N) break;
	}
	return 0;
} 
