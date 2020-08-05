#include <bits/stdc++.h>
#define MAX_N 30 + 1
using namespace std;

int N, D;

struct Box{
	int index;
	int L[12];

	bool operator < (const Box &other) const{
		for(int i = 0; i < D; i++)
			if(L[i] >= other.L[i]) return false;

		return true;
	}
};

Box input[MAX_N];
int pre[MAX_N], dp[MAX_N], ans;

void trace(int k){
	if(pre[k] != -1) trace(pre[k]);
	printf("%d", input[k].index);
	if(--dp[ans]) printf(" ");
	else printf("\n");
}

bool cmp(Box &a, Box &b){
	for(int i = 0; i < D; i++){
		if(a.L[i] < b.L[i]) return true;
		if(a.L[i] > b.L[i]) return false;
	}

	return a.index < b.index;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N >> D){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < D; j++)
				cin >> input[i].L[j];

			input[i].index = i + 1;
			sort(input[i].L, input[i].L + D);
		}

		sort(input, input + N, cmp);
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));

		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				if(input[i] < input[j] && dp[i] + 1 > dp[j]){
					dp[j] = dp[i] + 1;
					pre[j] = i;
				}
			}
		}

		for(int i = 1; i < N; i++)
			if(dp[i] > dp[ans]) ans = i;
		
		printf("%d\n", ++dp[ans]);

		trace(ans);
	}

	return 0;
}