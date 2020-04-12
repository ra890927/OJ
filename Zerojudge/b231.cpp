#include <iostream>
#include <algorithm>
using namespace std;

struct Book{
	int print, bind;
};
bool cmp(Book a, Book b){
	return a.bind > b.bind;
}

int main(){
	int n;
	while(cin>>n){
		int t = 0, s = 0;
		Book book[1000];
		for(int i = 0; i < n; i++)
			cin>>book[i].print>>book[i].bind;
		sort(book, book + n, cmp);
		for(int i = 0; i < n; i++){
			s += book[i].print;
			t = max(s + book[i].bind, t);
		}
		cout<<t<<endl;
	}
	return 0;
}