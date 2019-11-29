#include <iostream>
#include <vector>
using namespace std;
	
int main(){
	int  N, M, K, now;
	vector<int> v;
	while(cin >> N >> M >> K){
		v.clear();
		for(int i = 1; i <= N; i++)
			v.push_back(i);
		now = 0;
		for(int i = 0; i < K; i++){
			now = (now + M - 1) % v.size();
			v.erase(v.begin() + now);
		}
		if(v.size() == 1) cout << v[0] << endl;
		else if(now == v.size()) cout << v[0] << endl;
		else cout << v[now] << endl;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
	}
	return 0;
}
