#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll b, ll e)
{
    if(e==1) return 1;
    if(e&1)
    {
        ll now = power(b, e-1) * b;
        return now;
    }
    else
    {
        ll now = power(b, e/2);
        return now * now;
    }
}

int main()
{
    int n;
    cin >> n;

    int cnt=1;
    int low = 1, high = 1e9;
    int res=0;
    while(low <= high)
    {
        int mid=  (low+high)/2;
        cout << mid << endl;

        ll now = (ll)mid * 2LL * 4LL + (ll)(mid-1) * 4;
        now /= 2;

        if(now > n) high = mid - 1;
        else
        {
            res = now;
            cnt = mid+1;
            low = mid + 1;
        }
    }

    cout << res << " " << cnt << endl;

    n -= res;
    string ress[] = {"Sheldon", "Leonard", "Penny", "Rajesh"};
    cout << ress[n/cnt] << endl;
}

