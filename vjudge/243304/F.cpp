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
const int N=(int)1e3+10;
const int inf=(int)1e9;
const ll mod=(ll)1e9+7;
ll C[N];
vector<pair<int,int> >adj[N];
ll dist[N][101];
int done[N][101], cap;
void dijkstra(int n, int s, int e){
    CLR(done);
    priority_queue<pair<ll,pair<int,int> > > pq;
    for ( int i = 0; i < n; i++ ){
        for(int j = 0; j <= 100; j++) dist[i][j] = INF;
    }
    dist[s][0] = 0;
    pq.push({-0,{s,0}} );
    while (!pq.empty()){
        int s = pq.top().second.first;
        ll cost = pq.top().first * -1;
        int reserve = pq.top().ss.ss;
        pq.pop();
        if(s == e) return;
        if (done[s][reserve]) continue;
        int mn = 0, mx = cap - reserve;
      //  cout << s << " ## " << reserve << " " << cost << endl;
        for(; mn <= mx; mn ++){
            int cur = reserve + mn;
            for ( int i = 0; i < adj[s].size(); i++ ) {
                int t = adj[s][i].first;
                int e = adj[s][i].second;
                if(e > cur) continue;
                if (cost + 1LL * mn * C[s] < dist[t][cur - e]) {
                    dist[t][cur - e] = cost + 1LL * mn * C[s];
                    pq.push ({-dist[t][cur - e], {t, cur - e} });
              //  cout << t << " " << cur - e << " " << dist[t][cur - e ] << endl;
                }
            }
        }
        done[s][reserve] = 1;
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
        for(int i = 0; i < n; i++) cin >> C[i];
        for(int i = 1; i <= m; i++){
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int q;
        cin >> q;
        while(q--){
            int s, e;
            cin >> cap >> s >> e;
            dijkstra(n, s, e);
            ll cost = INF;
            for(int i = 0; i <= 100; i++) cost = min(cost, dist[e][i]);
            if(cost == INF) cout << "impossible" << endl;
            else cout << cost << endl;
        }
    }
    return 0;
}

