#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int depth[100001] = {};
vector<int> v[100001];
void dfs(int p, int d){
	depth[d]++;
	for(int i = 0; i < v[p].size(); i++){
		dfs(v[p][i], d + 1);
	}
}
int main(){
	int k, ans = 0;
	int cnt[100001];
	cin>>n;
	for(int i = 2; i <= n; i++){
		cin>>k;
		v[k].push_back(i);
	}
	memset(depth, 0, sizeof(depth));
	dfs(1,0);
	for(int i = 0; i < n; i++){
		ans += depth[i]%2;
	}
	cout<<ans<<endl;
}
