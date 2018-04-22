#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n++;
    while(1)
    {
        int nn = n;
        map <int, int> mp;
        int flg = 0;
        while(nn)
        {
            int kk = nn%10;
            nn /= 10;
            if(mp[kk])
            {
                flg = 1;
            }
            mp[kk]=1;
        }

        if(flg==0)
        {
            cout << n << endl;
            break;
        }
        n++;
    }
}
