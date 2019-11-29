#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 100000 + 1
using namespace std;

int a[MAX_N];
string s[MAX_N];
bool cmp(int a, int b){
	int res = min(s[a].length(), s[b].length());
	for(int i = 0; i < res; i++){
		if(s[a][i] < s[b][i]) return true;
		else return false;
	}
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		getline(cin, s[i]);
		a[i] = i;
	}
	sort(a, a + N, cmp);
	for(int i = 0; i < N; i++)
		cout << s[a[i]] << endl;
	return 0;
}