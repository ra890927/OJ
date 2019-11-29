#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int N;
	stack<int> s;
	vector<int> v;
	cin >> N;
	while(N--){
		int op, k;
		cin >> op;
		if(op == 1) s.pop();
		if(op == 2) v.push_back(s.top());
		if(op == 3){
			cin >> k;
			s.push(k);
		}
	}
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
