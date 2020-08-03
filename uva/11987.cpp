#include <bits/stdc++.h>
#define MAX_N 100000 + 1
using namespace std;

int N, M;
int Root[MAX_N];
vector<int> Set[MAX_N];

void init(){
	for(int i = 1; i <= N; i++){
        Root[i] = i;
        Set[i].clear();
        Set[i].push_back(i);
    }
}

void unite(int x, int y){
	x = Root[x];
    y = Root[y];

    if(x == y) return;

    if(Set[x].size() >= Set[y].size()){
        for(int &n : Set[y]){
            Set[x].push_back(n);
            Root[n] = x;
        }

        Set[y].clear();
    }
    else{
        for(int &n : Set[x]){
            Set[y].push_back(n);
            Root[n] = y;
        }

        Set[x].clear();
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> N >> M){
		init();
		int opt, x, y;

		while(M--){
			cin >> opt;

			if(opt == 1){
				cin >> x >> y;
				unite(x, y);
			}
			else if(opt == 2){
				cin >> x >> y;

				if (Root[x] == Root[y]) continue;

				auto iter = Set[Root[x]].begin();
				while(*iter != x) ++iter;
				Set[Root[x]].erase(iter);

				Set[Root[y]].push_back(x);
				Root[x] = Root[y];
			}
			else{
				cin >> x;
				int Sum = 0;
				for (int &n : Set[Root[x]])
					Sum += n;
				printf("%d %d\n", Set[Root[x]].size(), Sum);
			}
		}
	}

	return 0;
}