#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

struct Block{
	int64_t length;
	int64_t width;
	int64_t height;

	Block(int64_t length, int64_t width, int64_t height)
		: length(length), width(width), height(height){}

	bool operator < (const Block &other) const{
		return length < other.length;
	}
};

int N;
vector<Block> item;

int64_t solved(){
	int64_t dp[item.size() + 5] = {0};

	sort(item.begin(), item.end());
	for(int i = 0; i < item.size(); i++){
		dp[i + 1] = item[i].height;
		for(int j = 0; j <= i; j++){
			if(item[i].length > item[j].length && item[i].width > item[j].width)
				dp[i + 1] = max(dp[i + 1], dp[j + 1] + item[i].height);
		}
	}

	int64_t result = 0;
	for(int i = 0; i < item.size(); i++)
		result = max(result, dp[i]);
	return result;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int index = 1;
	while(cin >> N){
		if(!N) break;

		int64_t a, b, c;
		item.clear();
		for(int i = 0; i < N; i++){
			cin >> a >> b >> c;
			item.push_back(Block(a, b, c));
			item.push_back(Block(a, c, b));
			item.push_back(Block(b, a, c));
			item.push_back(Block(b, c, a));
			item.push_back(Block(c, a, b));
			item.push_back(Block(c, b, a));
		}

		printf("Case %d: maximum height = %ld\n", index++, solved());
	}

	return 0;
}