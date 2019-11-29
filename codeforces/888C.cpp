#include <iostream>
#include <cstring>
using namespace std;

string s;
bool binary(int x){
	int cnt[26]={};
	for(int i=0;i<x;i++){
		cnt[s[i]-'a']++;
	}
	for(int i=x;i<s.size();i++){
		if(cnt[s[i]-'a'] > 0) cnt[s[i]-'a']++;
		if(cnt[s[i-x]-'a'] > 0) cnt[s[i-x]-'a']--;
	}
	bool res=false;
	for(int i=0;i<26;i++)
		if(cnt[i]>0) res=true;
	return res;
}
int main(){
	cin>>s;
	int mid,lb=0,ub=s.length();
	while(ub-lb>1){
		mid=(lb+ub)/2;
		if(binary(mid)) ub=mid;
		else lb=mid;
	}
	cout<<ub<<endl;
}
