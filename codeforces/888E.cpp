#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int data[35];
	vector<int> v;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> data[i];
		data[i] %= m;
	}
	int n1 = n / 2;
	for(int i = 0; i < (1 << n1); i++){
		long long s = 0;
		for(int j = 0; j < n1; j++){
			if((i >> j) & 1) s += data[j];
		}
		s %= m;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	int n2 = n - n1, ans = 0;
	for(int i = 0; i < (1<<n2); i++){
		int s = 0;
		for(int j = 0; j < n2; j++){
			if((i>>j) & 1) s += data[n1 + j];
		}
		s %= m;
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), m - s) - 1;
		ans = max(ans, s + *it);
	}
	cout << ans << endl;
	return 0;
}
