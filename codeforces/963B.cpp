#include <iostream>
#include <vector>
#define MAXN 2000000 + 1
using namespace std;

bool res[MAXN];
int n, degree[MAXN];
vector<int> v[MAXN];

bool dfs(int k, int p){
	int cnt = 0;
	for(int i = 0; i < v[k].size(); i++){
		if(v[k][i] != p)
			cnt += !dfs(v[k][i], k);
	}
	res[k] = (degree[k] - cnt) % 2;
	return res[k];
}

void output(int k, int p){
	for(int i = 0; i < v[k].size(); i++){
		if(v[k][i] != p && !res[v[k][i]])
			output(v[k][i], k);
	}
	cout << k << endl;
	for(int i = 0; i < v[k].size(); i++){
		if(v[k][i] != p && res[v[k][i]])
			output(v[k][i], k);
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		if(k){
			v[k].push_back(i);
			v[i].push_back(k);
			degree[i]++;
			degree[k]++;
		}

	}
	
	if(!dfs(1, -1)){
		cout << "YES" << endl;
		output(1, -1);
	}
	else cout << "NO" << endl;
	return 0;
}
