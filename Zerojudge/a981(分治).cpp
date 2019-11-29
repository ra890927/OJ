#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
	int N, K;
	int a[30];
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N, greater<int>());
	map<long long, vector<int> > h1, h2;
	int n1 = N / 2;
	for(int i = 0; i < (1<<n1); i++){
		ll sum = 0;
		for(int j = 0; j < n1; j++)
			if((i>>j) & 1) sum += a[j];
		
		h1[sum].push_back(i);
	}
	
	int n2 = N - n1;
	for(int i = 0; i < (1<<n2); i++){
		ll sum = 0;
		for(int j = 0; j < n2; j++)
			if((i>>j) & 1) sum += a[j + n1];
			
		h2[sum].push_back(i<<n1);
	}
	
	set<int> ret;
	for(map<long long, vector<int> >::iterator it = h1.begin(); it != h1.end(); it++){
		ll f = ll(K - it->first);
		map<long long, vector<int> >::iterator jt = h2.find(f);
		if(jt != h2.end()){
			for(vector<int>::iterator vi = it->second.begin(); vi != it->second.end(); vi++){
				for(vector<int>::iterator vj = jt->second.begin(); vj != jt->second.end(); vj++)
					ret.insert(*vi | *vj);
			}
		}
	}
	
	if(!ret.size()) cout << "-1" << endl;
	for(set<int>::reverse_iterator it = ret.rbegin(); it != ret.rend(); it++){
		for(int i = N - 1; i >= 0; i--)
			if(((*it)>>i) & 1) cout << a[i] <<" ";
		cout << endl;
	}
	return 0;
} 
