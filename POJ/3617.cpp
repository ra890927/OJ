#include <iostream>
#include <cstring>
#define MAXN 2000
using namespace std;

int main(){
	int N;
	while(cin >> N){
		char s[MAXN];
		memset(s, 0, sizeof(s));
		for(int i = 0; i < N; i++){
			getchar();
			cin >> s[i];
		}
		int sum = 0;
		int a = 0, b = N - 1;
		while(a <= b){
			bool left = false;
			for(int i = 0; a + i <= b; i++){
				if(s[a + i] < s[b - i]){
					left = true;
					break;
				}
				else if(s[a + i] > s[b - i]){
					left = false;
					break;
				}
			}
		
			if(left) putchar(s[a++]);
			else putchar(s[b--]);
			sum++;
			if(sum % 80 == 0) cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
