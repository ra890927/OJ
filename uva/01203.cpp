#include <bits/stdc++.h>
using namespace std;

struct Node{
	int id;
	int time;
	int sum;

	bool operator > (const Node &other) const{
		if(sum == other.sum) return id > other.id;
		return sum > other.sum;
	}
};

int main(){
	int N;
	string s;
	priority_queue<Node, vector<Node>, greater<Node>> pri_q;

	while(cin >> s){
		if(s == "#") break;

		Node temp;
		cin >> temp.id >> temp.time;
		temp.sum = temp.time;
		pri_q.push(temp);
	}

	cin >> N;
	for(int i = 0; i < N; i++){
		Node n = pri_q.top();
		pri_q.pop();

		cout << n.id << endl;

		n.sum += n.time;
		pri_q.push(n);
	}

	return 0;
}