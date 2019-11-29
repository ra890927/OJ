#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,ans=0;
	int u=0,d=0,l=0,r=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='U') u++;
		if(s[i]=='D') d++;
		if(s[i]=='L') l++;
		if(s[i]=='R') r++;
	}
	ans+=2*min(u,d);
	ans+=2*min(l,r);
	cout<<ans<<endl;
}
