/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
handle: math10
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int64 ,int64 >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'|c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"    ";
        return *this;
    }
} dbg;
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e6 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int MAX_N = int(1e5) + 7;
const int MAX_E = int(1e6) + 7;
const int MAX_L = 22;
int N, M, colors[MAX_N];
int e, to[MAX_E], from[MAX_E], weight[MAX_E], head[MAX_N];

//{{{ ************[Centroid Decomposition]************
int sz[MAX_N], cut[MAX_N];
int64 dist[MAX_L][MAX_N];

struct Component {
    int id, pid, level;
    vector<int > children;

    Component() {}
    Component(int id, int pid, int level) :
        id (id), pid(pid), level(level) {
            children.clear();
    }

    void set_dist(int u, int64 d) { dist[level][u] = d; }
    int64 get_dist(int u) { return dist[level][u]; }

    friend ostream &operator <<(ostream &ostr, Component &comp) {
        ostr << "[id:" << comp.id;
        ostr << ", pid:" << comp.pid;
        ostr << ", level:" << comp.level;
        ostr << "]";

        return ostr;
    }
} CT[MAX_N];

int get_size(int u, int p = -1) {
    int &size = sz[u];
    size = 1;

    for (int e = head[u]; ~e; e = from[e]) {
        int v = to[e];
        if (v == p || cut[v]) continue;

        size += get_size(v, u);
    }

    return size;
}

pii get_centroid(int u, int p, int component_size) {
    int max_of_children_size = component_size - sz[u];
    pii best_child_candidate = pii(INT_MAX, INT_MAX);

    for (int e = head[u]; ~e; e = from[e]) {
        int v = to[e];
        if (v == p || cut[v]) continue;

        max_of_children_size = max(max_of_children_size, sz[v]);
        best_child_candidate = min(
            best_child_candidate,
            get_centroid(v, u, component_size)
        );
    }

    return min(best_child_candidate, pii(max_of_children_size, u));
}

void gen_dist(int u, int p, int64 d, int centroid) {
    CT[centroid].set_dist(u, d);

    for (int e = head[u]; ~e; e = from[e]) {
        int v = to[e];
        if (v == p || cut[v]) continue;

        gen_dist(v, u, d + weight[e], centroid);
    }
}

void decompose(int u, int pid = -1) {
    int centroid = get_centroid(u, -1, get_size(u)).second;
    if (~pid) CT[pid].children.pb(centroid);

    CT[centroid] = Component(centroid, pid, ~pid ? CT[pid].level + 1 : 0);
    gen_dist(centroid, -1, 0, centroid);

    cut[centroid] = true;
    for (int e = head[centroid]; ~e; e = from[e]) {
        int v = to[e];
        if (cut[v]) continue;
        decompose(v, centroid);
    }
}

void build_centroid_tree() {
    memo(cut,0);
    decompose(0);
}

void input(){
    N = II;
    memo(head, -1);
    rep(i, N - 1) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        --u, --v;
        to[e] = v, from[e] = head[u], weight[e] = w, head[u] = e++;
        to[e] = u, from[e] = head[v], weight[e] = w, head[v] = e++;
    }
}

int main(){
    #ifdef Sanim
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    input();
    build_centroid_tree();
}

