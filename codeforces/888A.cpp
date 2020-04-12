#include <iostream>
using namespace std;

int main(){
	int n,cnt=0;
	int k[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n-2;i++){
		if(k[i-1]<k[i] && k[i]>k[i+1]) cnt++;
		else if(k[i-1]>k[i] && k[i]<k[i+1]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
