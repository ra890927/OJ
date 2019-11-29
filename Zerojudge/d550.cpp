#include <cstdio>
#include <algorithm>
#define MAX_N 10000 + 1
#define MAX_M 200 + 1
using namespace std;

int N, M;
int array[MAX_N][MAX_M];

bool cmp(int i, int j){
	for(int k = 0; k < M; k++)
		if(array[i][k] != array[j][k])
			return array[i][k] > array[j][k];

	return false;
}

void change(int i, int j){
	for(int k = 0; k < M; k++)
		swap(array[i][k], array[j][k]);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &array[i][j]);
			
	for(int i = 0; i < N; i++){
		int res = i;
		for(int j = i+1; j < N; j++)
			if(cmp(res, j)) res = j;
			
		change(i, res);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
	
	return 0;
}