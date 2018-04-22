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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta007
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
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

#define MX 1000004
int arr[MX];

struct node {
	int size, prior;
    int val; //value stored in the array
    int maxy; //whatever info you want to maintain in segtree for each node
    node *l, *r;
	node(){}
	node(int val) {
		size = 1;
		this->val = val;
		prior = rand();
        maxy = val;
		l = r = NULL;
	}
} *root;

typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t) t->size = sz(t->l) + 1 + sz(t->r);
}

void reset(pnode t){
   if(t) t->maxy = t->val;//lazy already propagated
}
void combine(pnode& t,pnode l,pnode r){//combine segtree ranges
    if(!l || !r)return void(t = l?l:r);
    t->maxy = max(l->maxy, r->maxy) ;
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//node represents single element of array
    combine(t,t->l,t);combine(t,t,t->r);
}

void split(pnode t, pnode &l, pnode &r, int pos, int add=0){
    if(!t) return void(l=r=NULL);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
            split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else    split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){//result //left //right array
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else                       merge(r->l,l,r->l),t=r;
    upd_sz(t); operation(t);
}

/// For initialize or print
pnode init(int val){
    pnode ret = new node(val);
    return ret;
}
void initArray(int sz)
{
    for(int i=0; i<sz; i++)
    {
        pnode it = init( arr[i] );
        if(i==0) root = it;
        else merge(root, root, it);
    }
}
void display(pnode t, int level)
{
    if (!t) return;
    display(t->r, level + 1);
    cout<<endl;
    if (t == root)
   	    cout<<"Root->:  ";
    else
    {
        for (int i = 0; i < level; i++)
            cout<<"       ";
    }
    cout<<t->val;
    display(t->l, level + 1);
}
void output (pnode t) {
	if (! t) return;
	output (t-> l);
	printf ("%d", t-> val);
	output (t-> r);
}
void clear_tree(pnode t)
{
    if(!t) return;
    clear_tree(t->l);
    clear_tree(t->r);
    free(t);
}

/// Segment Tree Functions
int range_query(pnode t,int l,int r){//[l,r]
   pnode L,mid,R;
   split(t,L,mid,l-1);
   split(mid,t,R,r-l);//note: r-l!!
   // Answer will be the total ans of the ranges
   int ans = t->maxy;
   merge(mid,L,t);
   merge(t,mid,R);
   return ans;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   srand(time(NULL));
   int n;
   while(~scanf("%d", &n))
   {
       int flg = 1;
       FOR(i,1,n)
       {
           char ch;
           int l,r;
           scanf(" %c %d %d",&ch, &l, &r);
           // debug(ch, l, r)

           if(ch == 'A')
           {
               r--;
               pnode it = new node(l);
               if(flg==1) root = it;
               else
               {
                   pnode lf,rr, mid;
                   split(root, lf, rr, r-1);
                   merge(mid, lf, it);
                   merge(root, mid, rr);
               }
               flg = 0;
           }
           else
           {
               printf("%d\n", range_query(root, --l, --r));
           }
           // output(root);
       }
       clear_tree(root);
   }

    return 0;
}
