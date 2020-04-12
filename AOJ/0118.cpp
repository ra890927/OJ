#include <iostream>
#include <cstring>
#define MAXH 100
#define MAXW 100
using namespace std;

int H, W;
char farm[MAXH][MAXW];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x, char tree){
	for(int i = 0; i < 4; i++){
		int h = y + dy[i];
		int k = x + dx[i];
		if(h >= 0 && h < H && k >= 0 && k < W && tree == farm[h][k]){
			farm[h][k] = 'x';
			dfs(h, k, tree);
		}
	}
}

int main(){
	while(cin >> H >> W){
		if(!W && !H) break;
		memset(farm, 0, sizeof(farm));
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++)
				cin >> farm[i][j];
		}
		
		int sum = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(farm[i][j] != 'x'){
					sum++;
					dfs(i, j, farm[i][j]);
				}
			}
		}
		cout << sum <<endl;
	}
	return 0;
}
