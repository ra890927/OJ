#include <cstdio>
#include <vector>
using namespace std;

int main(){
	vector<int> n, m;
	int a, b, p, q, sum = 0;
	while(scanf("%d:%d", &a, &b) == 2){
		if(!a && !b) break;
		n.push_back(a);
		m.push_back(b);
	}
	
	while(scanf("%d:%d", &p, &q) == 2){
		if(!p && !q) break;
		for(int i = 0; i < n.size(); i++)
			if(p == n[i]) sum += m[i] * q;
	}
	
	printf("%d\n", sum);
	return 0;
}