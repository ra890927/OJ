#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> matrix;

int main(){
	ios::sync_with_stdio();
	cin.tie(0);

	int N;
	string s;
	map<char, matrix> Mat;
	cin >> N;

	for(int i = 0; i < N; i++){
		char name;
		matrix mat;

		cin >> name >> mat.first >> mat.second;
		Mat[name] = mat;
	}

	while(cin >> s){
		int count = 0;
		bool res = true;
		vector<matrix> vec;

		for(int i = 0; i < s.length(); i++){
			if(s[i] == '(') continue;
			else if(s[i] != ')'){
				vec.push_back(Mat[s[i]]);
				continue;
			}
			else{
				matrix q = vec.back();
				vec.pop_back();
				matrix p = vec.back();
				vec.pop_back();

				if(p.second != q.first){
					res = false;
					break;
				}

				count += p.first * q.first * q.second;

				matrix temp;
				temp.first = p.first, temp.second = q.second;
				vec.push_back(temp);
			}
		}

		if(res) printf("%d\n", count);
		else printf("error\n");
	}

	return 0;
}