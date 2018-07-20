#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define EPS 1e-9
#define PI acos(-1.0)
#define ff first
#define ss second
#define ALL(v) v.begin(),v.end()
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b){return (a/__gcd(a,b))*b;}
ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}
int biton(int n,int pos){return n=n | (1<<pos);}
int bitoff(int n,int pos){return n=n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n & (1<<pos));}
#ifdef shaft
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
const ll INF = (ll)1e18;
const int N=(int)1e6+1;
const int inf=(int)1e9;
const ll mod=(ll)1e9+7;
ll cost[210][20];
ll solve[210], penalty[210];
map<string,ll > mp;
int main(){
    ios_base::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(10);cout.tie(nullptr); cin.tie(nullptr);
    #ifdef shaft
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif ///shaft
    int n, m, p;
    while(cin >> n >> m >> p){
        int id = 0;
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            if(mp.find(s) == mp.end()) mp[s] = ++id;
        }
        ll lst = 0;
        ll res = 0;
        ll bst_solve = 0, bst_penalty = 0, flag = 1;
        for(ll i = 1; i <= m; i++){
            string s, ver; char ch; int t;
            cin >> s >> ch >> t >> ver;
            if(cost[mp[s]][ch-'A'] == -1) continue;
            if(ver == "OK"){
                solve[mp[s]] += 1;
                penalty[mp[s]] += cost[mp[s]][ch-'A'] + t;
                cost[mp[s]][ch-'A'] = -1;
                if(flag) res += (t-lst);
                if(solve[mp[s]] > bst_solve || (solve[mp[s]] == bst_solve && penalty[mp[s]] < bst_penalty)){
                    bst_solve = solve[mp[s]];
                    bst_penalty = penalty[mp[s]];
                    if(mp[s] == 1) flag = 1;
                    else flag = 0;
                }
                else if(solve[mp[s]] == bst_solve && penalty[mp[s]] == bst_penalty && mp[s] == 1) flag = 1;
            }
            else{
                cost[mp[s]][ch-'A'] += 20;
                if(flag) res += (t-lst);
            }
            lst = t;
        }
        if(flag) res += (300-lst);
        cout << res << endl;
    }
    return 0;
}

