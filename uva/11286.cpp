#include <bits/stdc++.h>
#define MAX_N 10000 + 1
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	while(cin >> N){
		if(!N) break;

		int ans = 0;
		map<string, int> string_map;
		map<string, int>::iterator iter;

		for(int i = 0; i < N; i++){
			string arr[5];

			for(int j = 0; j < 5; j++)
				cin >> arr[j];

			sort(arr, arr + 5);

			string s;

			for(int j = 0; j < 5; j++)
				s += arr[j];

			string_map[s] += 1;
		}

		int max = 0, total = 0;

		for(iter = string_map.begin(); iter != string_map.end(); iter++){
			if(iter->second > max){
				max = iter->second;
				total = iter->second;
			}
			else if(max == iter->second)
				total += iter->second;
		}

		printf("%d\n", total);
	}

	return 0;
}