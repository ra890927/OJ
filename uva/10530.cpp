#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;

	while(cin >> k && k != 0){
		string s;
		int lb = 0, ub = 11;

		while(getline(cin, s) && s != "right on"){
			if(s == "too high") ub = min(ub, k - 1);
			else if(s == "too low") lb = max(lb, k + 1);

			scanf("%d", &k);
		}

		if(k >= lb && k <= ub) printf("Stan may be honest\n");
		else printf("Stan is dishonest\n");
	}

	return 0;
}