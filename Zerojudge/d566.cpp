#include <iostream>
#include <cstring>
#include <map>
#define MAX_N 10000
using namespace std;

int main(){
	int N;
	cin >> N;
	map<string, int> m, R, A;
	string a[MAX_N], b[MAX_N];
	for(int i = N-1; i >= 0; i--)
		cin >> a[i] >> b[i];
	
	for(int i = 0; i < N; i++){
		if(b[i] == "AC" && m.find(a[i]) == m.end())
			R[a[i]] = 1;
		m[a[i]]++;
		if(b[i] == "AC") A[a[i]] = 1;
	}
	int ac = R.size(), sum = A.size();
	cout << ac * 100 / sum << "%" << endl;
	return 0;
}