#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		int sum = 0;
		for(int i = 1; i < N; i++)
			if(N % i == 0) sum += i;
		
		if(sum > N) cout << "�ռ�" << endl;
		else if(sum == N) cout << "������" << endl;
		else cout << "����" << endl;
	}
	return 0;
}