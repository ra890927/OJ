#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		int arr[N], cnt = 0;
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr, arr + N);
		
		for(int i = 0; i < N; i++)
			for(int j = i + 1; j < N; j++)
				for(int k = j + 1; k < N; k++)
					if(arr[i] * arr[i] + arr[j] * arr[j] == arr[k] * arr[k])
						cnt++;
		cout << cnt << endl;
	}
	return 0;
}