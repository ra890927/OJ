vector<int> shortestToChar(string s, char c){
	vector<int> v(s.length(), INT_MAX);
	vector<int> index;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == c){
			v[i] = 0;
			index.push_back(i);
		}
	}

	int dis = 1;
	while(true){
		for(int &k : index){
			if(k + dis < s.length()) v[k + dis] = min(v[k + dis], dis);
			if(k - dis >= 0) v[k - dis] = min(v[k - dis], dis);
		}

		bool check = false;
		for(int &num : v)
			if(num == INT_MAX) check = true;

		if(check) dis += 1;
		else break;
	}

	return v;
}