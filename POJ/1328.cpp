#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

struct point{
	double left, right;
	bool operator < (const point &other) const{
		return left < other.left;
	}
}p[MAX_N], temp;

int main(){
	int N, k = 1;
	double R;
	while(true){
		bool res = false;
		scanf("%d %lf", &N, &R);
		if(!N && !R) break;
		for(int i = 0; i < N; i++){
			double a, b;
			scanf("%lf %lf", &a, &b);
			if(fabs(b) > R) res = true;
			else{
				p[i].left = a * 1.0 - sqrt(R * R - b * b);
				p[i].right = a * 1.0 + sqrt(R * R - b * b);
			}
		}
		
		printf("Case %d: ", k++);
		if(res) printf("-1\n");
		else{
			int cnt = 1;
			sort(p, p + N);
			temp = p[0];
			
			for(int i = 1; i < N; i++){
				if(p[i].left > temp.right){
					cnt++;
					temp = p[i];
				}
				else if(p[i].right < temp.right) temp = p[i];
			}
			
			printf("%d\n", cnt);
		}
	}
	return 0;
}