#include <cstdio>
using namespace std;

int main(){
	int num;
	float f, ans = 0.0;
	char c;
	while(scanf("%d%c%f%c", &num, &c, &f, &c) == 4){
		if(num & 1) ans += f;
		else ans -= f;
		if(c == '\n'){
			printf("%g\n", ans);
			ans = 0.0;
		}
	}
	return 0;
}