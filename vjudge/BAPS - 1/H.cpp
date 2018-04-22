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
#define all(v) v.begin(),v.end()
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b){return (a/__gcd(a,b))*b;}
ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}


#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

#define NODE 1004
struct HopcroftKarp {
	static const int MAXV = 10000 + 10;
	static const int MAXE = 1000000 + 10;
	int nx, ny, E, adj[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV], matx[MAXV], maty[MAXV];
	void init(int _nx, int _ny) {
		nx = _nx; ny = _ny;
		E = 0; memset(last, -1, sizeof(last));
		memset(matx, -1, sizeof(matx)); memset(maty, -1, sizeof(maty));
	}
	void add(int x, int y) {
		adj[E] = y; next[E] = last[x]; last[x] = E++;
	}
	bool bfs() {
		int qsize = 0;
		for (int x = 1; x <= nx; x++) if (matx[x] != -1) level[x] = -1;
		else {
			level[x] = 0;
			que[qsize++] = x;
		}
		bool found = false;
		for (int i = 0; i < qsize; i++) {
			for (int x = que[i], e = last[x]; e != -1; e = next[e]) {
				int y = adj[e];
				if (maty[y] == -1) found = true;
				else if (level[maty[y]] == -1) {
					level[maty[y]] = level[x] + 1;
					que[qsize++] = maty[y];
				}
			}
		}
		return found;
	}
	int dfs(int x) {
		for (int &e = run[x]; e != -1; e = next[e]) {
			int y = adj[e];
			if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y]))) {
				matx[x] = y;
				maty[y] = x;
				return 1;
			}
		}
		return 0;
	}
	int maxmat() {
		int total = 0;
		while (bfs()) {
			for (int x = 1; x <= nx; x++) run[x] = last[x];
			for (int x = 1; x <= nx; x++) if (matx[x] == -1) total += dfs(x);
		}
		return total;
	}
} hopkarp;

int mark[NODE][NODE];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("perfect.in","r",stdin);
    freopen("perfect.out","w",stdout);
    int n;
    while(cin >> n){
        clr(mark);
        for(int i = 1; i <= n; i++){
            int tot;
            cin >> tot;
            for(int j = 1; j <= tot; j++){
                int x; cin >> x;
                if(x <= n && x>=1) mark[i][x] = 1;
            }
        }
        hopkarp.init(n+4, n+4);
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(mark[i][j] && mark[j][i])
                {
                    hopkarp.add(i, j);
//                    hopkarp.add(j, i);
                }
            }
        }
        int maxmatch = hopkarp.maxmat();

        debug(maxmatch);
        if(n != maxmatch*2)
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}


