#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[5], cnt[5];
void recursion(int money, int index){
	if(money == 0){
		cout << "(" << cnt[0];
		for(int i = 1; i < N; i++)
			cout << "," << cnt[i];
		cout << ")" << endl;
		return;
	}
	
	if(index >= N || money < 0) return;
	int t = money / arr[index];
	for(int i = 0; i <= t; i++){
		cnt[index] = i;
		recursion(money - arr[index] * i, index + 1);
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> K;
	recursion(K, 0);
	return 0;
}