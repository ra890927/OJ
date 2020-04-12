#include <iostream>
#include <deque>
using namespace std;

int main(){
	int N, k;
	while(cin >> N){
		bool res = true;
		deque<int> v;
		for(int i = 0; i < N; i++){
			cin >> k;
			v.push_back(k);
		}
		while(N--){
			if(res){
				for(int i = 0; i < v.size(); i++)
					cout << v[i] << " ";
				cout << endl;
				v.pop_front();
				res = false;
			}
			else{
				for(int i = v.size()-1; i >= 0; i--)
					cout << v[i] << " ";
				cout << endl;
				v.pop_back();
				res = true;
			}
		}
	}
	return 0;
}