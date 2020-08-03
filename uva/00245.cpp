#include <bits/stdc++.h>
using namespace std;

struct Node{
	string word;
	Node *next;
};

bool is_alphabet(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else return false;
}

bool is_number(char c){
	if(c >= '0' && c <= '9') return true;
	else return false;
}

int main(){
	Node *head = NULL;
	char input = 0;
	input = getchar();

	while(true){
		if(is_alphabet(input)){
			string output;

			while(is_alphabet(input)){
				output += input;
				input = getchar();
			}

			cout << output;

			Node *temp = new Node;
			temp->word = output;
			temp->next = head;
			head = temp;
			temp = NULL;
			delete temp;
		}
		else if(is_number(input)){
			if(input == '0') break;

			int num = 0;

			while(is_number(input)){
				num = num * 10 + input - '0';
				input = getchar();
			}

			Node *now = head;
			Node *pre = NULL;
			for(int i = 1; i < num; i++){
				pre = now;
				now = now->next;
			}
			cout << now->word;

			if(now != head){
				pre->next = now->next;
				now->next = head;
				head = now;
			}
		}
		else{
			printf("%c", input);
			input = getchar();
		}
	}

	return 0;
}