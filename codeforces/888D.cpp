#include <iostream>
using namespace std;

int N,K;
int c[5]={0,1,1,2,9};
int fac[5]={1,1,2,6,24};
long long solve(int n, int k){
	if(k==1) return 1;
	else{
		unsigned long long ll=1;
		for(int i=n;i>n-k;i--)
			ll*=i;
		ll/=fac[k];
		ll*=c[k];
		return ll+solve(n,k-1);
	}
}
int main(){
	while(cin>>N>>K)
		cout<<solve(N,K)<<endl;
}
