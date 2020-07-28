#include <bits/stdc++.h>
#define MAX_N 10000 + 1
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int data[MAX_N][11];
	unordered_map<string, int> str_map;

	while(~scanf("%d %d", &N, &M)){
		getchar();
		str_map.clear();

		char c;
		string s;
		int count = 1;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				data[i][j] = 0;

				while((c = getchar()) != ',' && c != '\n')
					s += c;

				if(!str_map.count(s)) str_map[s] = count++;

				data[i][j] = str_map[s];
				s.clear();
			}
		}

		bool check = true;
		unordered_map<int64_t, int> col_data;

		for(int c1 = 0; c1 < M && check; c1++){
			for(int c2 = c1 + 1; c2 < M && check; c2++){
				for(int r = 0; r < N; r++){
					int64_t s1 = data[r][c1], s2 = data[r][c2];
					int64_t temp = (s1 + s2 - 2) * (s1 + s2 - 1) / 2 + s2;

					if(!col_data.count(temp))
						col_data[temp] = r;
					else{
						check = false;
						printf("NO\n");
						printf("%d %d\n%d %d\n", col_data[temp] + 1, r + 1, c1 + 1, c2 + 1);
						break;
					}
				}

				col_data.clear();
			}
		}

		if(check) printf("YES\n");
	}

	return 0;
}