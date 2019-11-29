#include<cstdio>  
const int mod = 1e9;  
const int maxn = 1000001;  
  
int f[maxn];  
  
int main()  
{  
    int n, i;  
    f[1] = 1, f[2] = 2;  
    for (i = 3; i < maxn; ++i)  
        f[i] = (i & 1 ? f[i - 1] : (f[i - 2] + f[i >> 1]) % mod) ;  
    while (~scanf("%d", &n))  
        printf("%d\n", f[n]);  
    return 0;  
}  
