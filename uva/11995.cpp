#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;

	while(cin >> N){
		int k, opt;
		stack<int> S;
		queue<int> Q;
		priority_queue<int> P;

		int is_stack = 1;
		int is_queue = 1;
		int is_pri_q = 1;
		bool impossible = false;

		for(int i = 0; i < N; i++){
			cin >> opt >> k;

			if(opt == 1){
				S.push(k);
				Q.push(k);
				P.push(k);
			}
			else if(opt == 2){
				int temp;

				if(S.empty() || Q.empty() || P.empty()){
					impossible = true;
					continue;
				}

				temp = S.top(), S.pop();
				if(temp != k) is_stack = 0;

				temp = Q.front(), Q.pop();
				if(temp != k) is_queue = 0;

				temp = P.top(), P.pop();
				if(temp != k) is_pri_q = 0;
			}
		}

		if(impossible)
			printf("impossible\n");
		else if(is_stack + is_queue + is_pri_q > 1)
			printf("not sure\n");
		else if(is_stack)
			printf("stack\n");
		else if(is_queue)
			printf("queue\n");
		else if(is_pri_q)
			printf("priority queue\n");
		else
			printf("impossible\n");
	}

	return 0;
}