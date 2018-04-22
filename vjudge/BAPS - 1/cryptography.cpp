////#if !defined(YCM) && 1
////#define _FORTIFY_SOURCE 0
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
////#pragma GCC target("avx")
//////#pragma GCC optimize ("O3")
//////#pragma GCC target ("sse4")
////#include <stdio.h>
////#endif
//#include <unistd.h>
////#pragma GCC diagnostic ignored "-Wunused-result"
////#pragma GCC diagnostic ignored "-Wunused-function"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define clr(a) memset(a,0,sizeof(a))
#define clr_(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define eps 1e-9
#define inf INT_MAX
#define pi acos(-1.0)
#define ff first
#define ss second
#define INF (ll)1e18
#define m_p make_pair

#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define all(v) v.begin(),v.end()
int fx[]= {0,0,-1,1,-1,1,1,-1};
int fy[]= {1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}
ll bigmod(ll a,ll p,ll mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}
ll power(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        ll y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}

#ifdef dipta007
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma - names) << " is " << arg1 <<endl;
    __f(comma+1, args...);
}
#else
#define debug(...)
#endif
const int N=(int)1e6+5;
const int mod=(int)1e9+7;
vector<pii>v[10000];
int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifdef shaft
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif ///shaft
    int n, a, b;
    while(cin >> n)
    {
        vector <int>  v[n+4];
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if((i&j) == i)
                {
                    v[i].push_back(j);
                }
            }
        }

        debug( (2&1) );
        FOR(i,1,n) debug(i, v[i].size());

        cout <<n<<endl;
        for(a = 1; a <= 10; a++)
        {
            for(b = a; b <= 10; b++)
            {
                int sum = -1;
                vector<int>x,y;
                int p=-1,q=-1;
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if((i&j) == j) /// x & y = y
                        {
                            int res = (a*i+b*j)^(a*j+b*i);
                            if(res > sum)
                            {
                                sum = res;
                                x.clear();
                                y.clear();
                                x.pb(i);
                                y.pb(j);
                                p = i, q= j;
                            }
                            else if(res == sum)
                                x.pb(i);
                        }
                    }
                }
                // v[a+b].pb(m_p(p,q));
                cout <<a<<" "<<b<<" "<<p << " "<<q<<" "<<x.size() << " " << sum <<endl;
            }
        }
//        for(int i = 0; i <= a+b; i++){
//            sort(all(v[i]));
//            debug(i);
//            for(pii j : v[i])
//                cout << j.ff<<" "<<j.ss<<endl;
//        }
        cout <<"*********"<<endl;
        //cout << x.size() <<" "<<y.size()<<endl;
    }
    return 0;
}



