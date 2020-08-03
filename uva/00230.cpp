#include <bits/stdc++.h>
#define MAX_N 1000 + 1
using namespace std;

struct Book{
	string name;
	string author;

	bool operator < (const Book &other) const{
		if(author != other.author) return author < other.author;
		return name < other.name;
	}
};

Book book[MAX_N];
map<string, int> value;

int find_prev(int cur){
	for(int i = cur - 1; i >= 0; i--)
		if(value[book[i].name] == 1) return i;

	return -1;
}

int main(){
	int index = 0;
	string input;

	while(getline(cin, input)){
		if(input == "END") break;

		string name;
		string author;
		bool change = false;
		name += input[0];
		for(int i = 1; i < input.length(); i++){
			if(input[i] == '"'){
				name += input[i];
				change = true;
				i += 4;
			}
			
			if(change) author += input[i];
			else name += input[i];
		}

		book[index].name = name, book[index].author = author;
		value[book[index].name] = 1;
		index += 1;
	}

	sort(book, book + index);

	while(cin >> input){
		if(input == "END") break;

		if(input == "BORROW"){
			getchar();
			getline(cin, input);
			value[input] = 0;
		}
		else if(input == "RETURN"){
			getchar();
			getline(cin, input);
			value[input] = 2;
		}
		else if(input == "SHELVE"){
			for(int i = 0; i < index; i++){
				if(value[book[i].name] == 2){
					int pos = find_prev(i);

					if(pos == -1)
						cout << "Put " << book[i].name << " first" << endl;
					else
						cout << "Put " << book[i].name << " after " << book[pos].name << endl;

					value[book[i].name] = 1;
				}
			}

			printf("END\n");
		}
	}

	return 0;
}