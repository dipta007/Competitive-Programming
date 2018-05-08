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
const int N=(int)2e5+1;
const int inf=(int)1e9;
const ll mod=(ll)1e9+7;
int level[N], shine[N];
int mx;
vector<int>value[21];
int st[N];
vector<int>adj[N];
void dfs(int src, int lvl){
    level[src] = lvl;
    value[lvl].pb(shine[src]);
    int len = value[lvl].size();
    st[src] = len-1;
    mx = max(mx, lvl);
    for(int v : adj[src]) dfs(v, lvl+1);
}
void precalc(){
    for(int i = 1; i <= mx; i++){
        for(int j = 1; j < value[i].size(); j++) value[i][j] += value[i][j-1];
    }
}
int main(){
    ios_base::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(10);cout.tie(nullptr); cin.tie(nullptr);
    #ifdef shaft
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif ///shaft
    int n, m;
    while(cin >> n >> m){
        cin >> shine[1];
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            shine[u] = w;
            adj[v].pb(u);
        }
        for(int i = 1; i <= 20; i++)value[i].pb(0);
        mx = 0;
        dfs(1, 1);
        precalc();

        while(m--){
            int root; cin >> root;
            int c = 1;
            int res = 0;
            for(int i = 1; i <= mx; i++){
                //for(int j : value[i]) cout << j << " ";
                //cout << endl;
                int temp = value[i].back();
                if(level[root] == i){
                   // debug(root);
                    int l = st[root];
                    int r = min(l+c-1, (int)value[i].size()-1);
                    //debug(l,r);
                    temp -= value[i][r] - value[i][l-1];
                    c *= 2;
                    int x = 0, y = 0;
                    if(adj[root].size() == 2){
                        x = adj[root][0], y = adj[root][1];
                        if(st[x] < st[y]) root = x;
                        else root = y;
                    }
                    else if(adj[root].size() == 1) root = adj[root][0];
                }
               // debug(temp,root);
                res = max(res, temp);
            }
            cout << res << endl;
        }
    }
    return 0;
}

