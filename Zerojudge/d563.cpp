#include <iostream>
#define MAX_N 100000
using namespace std;

int main(){
	int N, array[MAX_N];
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> array[i];
	int left = 0, right = N - 1, ans = 1;
	int res = array[left] - array[right];
	while(left < N-1 && right > 0){
		if(res > 0) res -= array[--right];
		else if(res < 0) res += array[++left];
		else{
			ans++;
			res += array[++left];
		}
	}
	cout << ans << endl;
	return 0;
}