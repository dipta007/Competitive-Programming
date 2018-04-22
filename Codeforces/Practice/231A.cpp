#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int kk = a+b+c;
        if( kk >= 2 ) cnt++;
    }
    cout << cnt << endl;
}
