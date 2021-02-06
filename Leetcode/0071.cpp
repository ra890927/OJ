string simplifyPath(string path){
	vector<string> v;
	int next, current = 0;

	while(true){
		next = path.find_first_of("/", current);
		if(next != current){
			string token = path.substr(current, next - current);
			if(token == ".." && !v.empty()) v.pop_back();
			else if(!token.empty() && token != "." && token != "..")
				v.push_back(token);
		}
		if(next >= path.length()) break;
		current = next + 1;
	}

	string ret;
	for(string &s : v) ret += '/' + s;
	if(ret.empty()) ret += '/';

	return ret;
}