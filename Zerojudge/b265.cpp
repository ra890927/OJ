#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int N;
	map<long long int, int> m;
	while(cin >> N){
		if(!N) break;
		m.clear();
		int cnt = 0;
		for(int i = 0; i < N; i++){
			int a[5];
			long long int s = 0;
			for(int i = 0; i < 5; i++)
				cin >> a[i];
			sort(a, a + 5);
			for(int i = 0; i < 5; i++){
				s *= 1000;
				s += a[i];
			}
			
			map<long long int, int>::iterator it = m.find(s);
			if(it != m.end()) m[s]++;
			else m[s] = 1;
			//cout << s << " " << m[s] << endl;
			cnt = max(cnt, m[s]);
		}
		
		int ans = 0;
		for(map<long long int, int>::iterator it = m.begin(); it != m.end(); it++)
			if(cnt == it->second) ans += it->second;
		cout << ans << endl;
	}
	return 0;
} 
