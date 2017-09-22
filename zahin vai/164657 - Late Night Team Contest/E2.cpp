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
#include <unordered_map>
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
#define    vi 	 vector < int >
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

#ifdef dipta007
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

//struct hashmap{
//    int t, sz, hmod;
//    vector <int> id;
//    vector <long long> key, val;
//
//    inline int nextPrime(int n){
//        for (int i = n; ;i++){
//            for (int j = 2; ;j++){
//                if ((j * j) > i) return i;
//                if ((i % j) == 0) break;
//            }
//        }
//        return -1;
//    }
//
//    inline int pos(unsigned long long x){
//        int i = x % hmod;
//        while (id[i] == t && key[i] != x) i++;
//        return i;
//    }
//
//    /// clears hashmap, equivalent to map.clear()
//    void clear(){t++;}
//
//    /// insert key x and set it to v, equivalent to map[x] = v
//    inline void insert(long long x, long long v){
//        int i = pos(x);
//        if (id[i] != t) sz++;
//        key[i] = x, val[i] = v, id[i] = t;
//    }
//
//    /// erase key x from the hashmap if exists
//    inline void erase(long long x){
//        int i = pos(x);
//        if (id[i] == t) key[i] = 0, val[i] = 0, id[i] = 0, sz--;
//    }
//
//    /// returns the value assigned to key x, -1 if no value is assigned, equivalent to map[x]
//    inline long long find(long long x){
//        int i = pos(x);
//        return (id[i] != t) ? -1 : val[i];
//    }
//
//    /// check if x contained in hashmap, equivalent to map.count(x)
//    inline bool contains(long long x){
//        int i = pos(x);
//        return (id[i] == t);
//    }
//
//    /// add v to index x, equivalent to map[x] += v
//    inline void add(long long x, long long v){
//        int i = pos(x);
//        (id[i] == t) ? (val[i] += v) : (key[i] = x, val[i] = v, id[i] = t, sz++);
//    }
//
//    /// size of hashmap, equivalent to map.size()
//    inline int size(){
//        return sz;
//    }
//
//    hashmap(){}
//    hashmap(int m){ /// m = maximum number of keys to be inserted in hashmap
//        srand(time(0));
//        m = m * 3 - ran(1, m);
//        hmod = nextPrime(max(100, m));
//
//        sz = 0, t = 1;
//        id.resize(hmod + 0x1FF, 0);
//        key.resize(hmod + 0x1FF, 0), val.resize(hmod + 0x1FF, 0);
//    }
//};


// 8 direction
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};

char adj[204][204];
int vis[204][204];
int tt,r,c;
int ix,iy,ik;
unordered_map <string, int> mp;

void dfs(int x, int y, int in, string st)
{

    if(st.size()>1) mp[st]++;
    if(x<0 || x>=r || y<0 || y>=c)
    {
//        //insert(st, st.size());
//        if(st=="001") debug(st,ix,iy,ik)
        return;
    }
    if(vis[x][y]==tt) return;
    vis[x][y] = tt;

    dfs(x+dx[in], y+dy[in], in, st + (adj[x][y]));
}


int main() {
    #ifdef dipta007
        READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> c >> r)
    {
        mp.clear();
//        root = new node();
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                char ch;
                cin >> ch;
                string tmp = "";
                tmp += ch;
                adj[i][j] = ch;
                mp[tmp]++;
            }
        }

        tt=0;
        CLR(vis);
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                FOR(k,0,7)
                {
                    tt++;
//                    ix=i,iy=j,ik=k;
                    //debug(i,j,k)
                    dfs(i,j,k,"");
                }
            }
        }

        int q;
        cin >> q;
        vector < string > vs;
        FOR(i,1,q)
        {
            string st;
            cin >> st;
            vs.PB(st);
        }
        sort(ALL(vs));
        FOR(i,0,q-1)
        {
            if(mp[vs[i]]>0)
            {
                cout << vs[i] << " " << mp[vs[i]] << endl;
            }
        }
        cout << "---" << endl;

//        del(root);
    }

    return 0;
}



