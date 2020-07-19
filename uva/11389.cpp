#include <bits/stdc++.h>
#define MAX_N 100 + 1
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, D, R;

	while(cin >> N >> D >> R){
		if(!(N + D + R)) break;

		int morning[MAX_N], night[MAX_N];

		for(int i = 0; i < N; i++)
			cin >> morning[i];
		for(int i = 0; i < N; i++)
			cin >> night[i];

		sort(morning, morning + N);
		sort(night, night + N);

		int fare = 0;

		for(int i = 0; i < N; i++){
			if(morning[i] + night[N - i - 1] > D)
				fare += morning[i] + night[N - i - 1] - D;
		}

		printf("%d\n", fare * R);
	}

	return 0;
}