#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b;

	while(cin >> a >> b){
		bool ans = true;
		int a_cnt[26] = {0};
		int b_cnt[26] = {0};

		for(int i = 0; i < a.length(); i++){
			a_cnt[a[i] - 'A'] += 1;
			b_cnt[b[i] - 'A'] += 1;
		}

		sort(a_cnt, a_cnt + 26, greater<int>());
		sort(b_cnt, b_cnt + 26, greater<int>());

		for(int i = 0; i < 26; i++)
			if(a_cnt[i] != b_cnt[i]) ans = false;

		if(ans) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}