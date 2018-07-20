#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;


#define mx 100001
map < double, int > mp;
map < int, double > rev;

int arr[mx];
struct info
{
    int sum;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    tmp.prop = 0;
    return tmp;
}
void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].sum = 0;
	    tree[node].prop = 0;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop=0;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	///update propagation
	tree[Left].prop += tree[node].prop;
	tree[Right].prop += tree[node].prop;
    tree[node].prop=0;
    ///update tree[left].sum
    int len = rev[mid] - rev[b];
    tree[Left].sum += (tree[Left].prop * len);
    ///update tree[right].sum
    len = rev[e] - rev[mid+1];
    tree[Right].sum += (tree[Right].prop * len);
}
void update(int node,int b,int e,int i,int j, int newVal)
{
    trace(node, b, e, i, j);
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        ///do something
        int len = rev[e] - rev[b];
        tree[node].prop += newVal;
        trace(b,e, newVal, len);
        tree[node].sum += (len * newVal);
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,newVal);
	update(Right,mid+1,e,i,j,newVal);
	tree[node]=call(tree[Left],tree[Right]);
}

struct data {
    double x, ly, hy;
    int flg;

    data() {}
    data(double _x, double _ly, double _hy, int _flg)
    {
        x = _x, ly = _ly, hy = _hy, flg = _flg;
    }
    bool const operator < (data b) const {
        if(x == b.x) return flg < b.flg;
        return x < b.x;
    }
};

vector < data > vd;
vector < double > v;

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, ci = 1;
    (getI(n));
    {
//        if(n == 0) break;

        mp.clear();
        rev.clear();
        vd.clear();

        FOR(i,1,n)
        {
            double x,y,a,b;
            getF(x);
            getF(y);
            getF(a);
            getF(b);

            vd.PB( data(x, y, b, 1));
            vd.PB( data(a, y, b, -1));

            v.PB(y);
            v.PB(b);
        }

        sort(ALL(v));
        UNIQUE(v);

        FOR(i, 0, (int)v.size()-1)
        {
            trace(i, v[i]);
            mp[v[i]] = i+1;
            rev[i+1] = v[i];
        }

        int totLen = v.size() + 1;
        sort(ALL(vd));
        init(1, 0, totLen);

        double res = 0;
        double px = vd[0].x;
        FOR(i,0,(int)vd.size()-1)
        {
            data d = vd[i];

            trace(d.x, d.ly, d.hy, d.flg);
            if(d.flg == -1)
            {
                double diff = vd[i].x - px;
                res += (diff * tree[1].sum);
                trace(-1, diff, tree[1].sum);
                px = vd[i].x;
                update(1, 0, totLen, mp[d.ly], mp[d.hy], -1);
            }
            else
            {
                double diff = vd[i].x - px;
                res += (diff * tree[1].sum);
                trace(-1, diff, tree[1].sum);
                px = vd[i].x;
                update(1, 0, totLen, mp[d.ly], mp[d.hy], 1);
            }
        }

        pf("Test case #%d\n", ci++);
        pf("Total explored area: %.2f\n", res);
        pf("\n");
    }

    return 0;
}


