#include <bits/stdc++.h>
using namespace std;
main() {
    int t;cin >> t; while(t--){ int a;cin >> a;long long res=LONG_LONG_MAX;
    for(long long i=a+1;i<=3*a;i++) if((1+i*a)%(i-a)==0)res=min(res,i+(1+i*a)/(i-a));printf("%lld\n",res);}}
