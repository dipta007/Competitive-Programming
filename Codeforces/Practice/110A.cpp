#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    int cnt = 0;
    while(n)
    {
        int kk = n % 10;
        n/=10;

        if(kk==4 || kk==7) cnt++;
    }
    if(cnt==4 || cnt==7) printf("YES\n");
    else printf("NO\n");
}
