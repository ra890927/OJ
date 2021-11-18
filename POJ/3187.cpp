#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, S;
int times[11][11];
vector<int> v;

bool check(){
	int sum = 0;
	for(int i = 0; i < N; i++)
		sum += v[i] * times[N-1][i];

	return sum == S;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;

	for(int i = 1; i <= N; i++)
		v.push_back(i);

	times[0][0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			times[i+1][j] += times[i][j];
			times[i+1][j+1] += times[i][j];
		}
	}

	while(!check())
		next_permutation(v.begin(), v.end());
	
	for(int i = 0; i < N; i++)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}