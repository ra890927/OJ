#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	long long a, b, p, q, r;
	while(scanf("%ld %ld %ld %ld %ld", &a, &b, &p, &q, &r) == 5){
		long long res = abs(p - a) + abs(q - b);
		puts(res > r ? "alive" : "die");
	}
	return 0;
}