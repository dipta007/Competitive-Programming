#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	 vector < ll >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifndef ONLINE_JUDGE
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
}dbg;

//#define MAX 254
//
//vector < int > edges[MAX];
//bool visited[MAX];
//int Left[MAX], Right[MAX];
//
//bool dfs(int u) {
//	if(visited[u]) return false;
//	visited[u] = true;
//	int len = edges[u].size(), i, v;
//	for(i=0; i<len; i++) {
//		v = edges[u][i];
//		if(Right[v]==-1) {
//			Right[v] = u, Left[u] = v;
//			return true;
//		}
//	}
//	for(i=0; i<len; i++) {
//		v = edges[u][i];
//		if(dfs(Right[v])) {
//			Right[v] = u, Left[u] = v;
//			return true;
//		}
//	}
//	return false;
//}
//
//int match(int n)
//{
//	SET(Left);
//	SET(Right);
//	int i, ret = 0;
//	bool done;
//	do
//	{
//		done = true;
//		CLR(visited);
//		rep(i,n)if(Left[i]==-1 && dfs(i))done = false;
//	}while(!done);
//	rep(i,n) ret += (Left[i]!=-1);
//	return ret;
//}

#define MAX 62504
#define NIL 0

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
int nn;
int k;
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
	int i, u, v, len;
	queue< int > Q;
	for(i=1; i<=n; i++) {
		if(match[i]==NIL) {
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = INF;
	}
	dist[NIL] = INF;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		if(u!=NIL) {
			len = G[u].size();
			for(i=0; i<len; i++) {
				v = G[u][i];
				if(dist[match[v]]==INF) {
					dist[match[v]] = dist[u] + 1;
					Q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

bool dfs(int u) {
	int i, v, len;
	if(u!=NIL) {
		len = G[u].size();
		for(i=0; i<len; i++) {
			v = G[u][i];
			if(dist[match[v]]==dist[u]+1) {
				if(dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp() {
	CLR(match);
	int matching = 0, i;
	// match[] is assumed NIL for all vertex in G
	while(bfs())
		for(i=1; i<=n; i++)
			if(match[i]==NIL && dfs(i))
				matching++;
	return matching;
}


vi a,b;
map <ll, int> mp, mp1;

ll check(ll val)
{
	mp.clear();
	mp1.clear();
	FOR(i,0,MAX-1) G[i].clear();
	int in1 =1, in2 = n+1;
	FOR(i,0,nn-1)
	{
		FOR(j,0,m-1)
		{
			ll aa = a[i] + val;
			ll bb = b[j];
			if(abs(aa-bb) <= k)
			{
				if(mp[aa]==0) mp[aa] = in1++;
				if(mp1[bb]==0) mp1[bb] = in2++;
				
				G[mp[aa]].PB(mp1[bb]);
			}
		}
	}
	return hopcroft_karp();
}

int main() {
#ifdef ONLINE_JUDGE
	//READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	getI(t);
	FOR(ci,1,t)
	{
		a.clear();
		b.clear();
		getIII(n,m,k);
		
		FOR(i,1,n)
		{
			ll x;
			getL(x);
			a.PB(x);
		}
		
		FOR(i,1,m)
		{
			ll x;
			getL(x);
			b.PB(x);
		}
		
		sort(ALL(a));
		sort(ALL(b));
		
		ll maxy = -2000000000;
		
		FOR(i,0,n-1)
		{
			FOR(j,0,m-1)
			{
				maxy = max(abs(a[i]- b[j]) + k, maxy);
			}
		}
		
		nn= n;
		n= max(n,m);
		/*
		set <int > s;
		FOR(i,0,n-1)
		{
			FOR(j,0,m-1)
			{
				s.insert(abs(a[i]-b[j]));
			}
		}
		
		set <int> :: iterator it;
		ll ans = 0;
		for(it=s.begin(); it!=s.end(); it++)
		{
			ll kk = *it;
			ans = max(ans, check(kk));
			ans = max(ans, check(-kk));
		}
		 */
		
		ll min = -maxy;
		ll max = maxy;
		int c = 100; //for higher precision have to increase
		ll k, l, f, g;
		while (c--) {
			f = min + (max - min) / (ll) 3;
			g = min + (ll) 2 * ((max - min) / (ll) 3);
			k = check(f);
			l = check(g);
			if (k > l) {
				max = g;
			} else {
				min = f;
			}
		}
		debug(min, max)
		ll ans = check(0);
		FOR(i,min, max)
		{
			ans = _max(ans, check(i));
			debug(ans, i)
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}


