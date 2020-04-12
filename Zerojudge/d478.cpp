#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(){
	int n, k ,t;
	scanf("%d %d", &n, &k);
	for(int j = 0; j < n; j++){
		int sum = 0;
		map<int, bool> m;
		map<int, bool>::iterator it;
		for(int i = 0; i < k; i++){
			scanf("%d", &t);
			m[t] = true;
		}
		for(int i = 0; i < k; i++){
			scanf("%d", &t);
			it = m.find(t);
			if(it->second) sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}