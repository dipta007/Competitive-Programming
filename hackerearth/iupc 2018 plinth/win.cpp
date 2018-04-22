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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta0
#ifdef dipta007
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

typedef struct node{
    int prior,size,val,lazy;
    //value in array,info of segtree,lazy update
    struct node *l,*r;
};

typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}

void lazy(pnode t){
    if(!t || !t->lazy)return;

    if(t->lazy)
    {
        //debug(t->lazy, t->val, sz(t));
        t->val += ( t->lazy ); 
    }

    //swap(t->l, t->r);

    if(t->l) t->l->lazy += t->lazy;//propagate lazy
    if(t->r) t->r->lazy += t->lazy;
    t->lazy=0;
}
//void reset(pnode t){
//    if(t)t->sum = t->val;//lazy already propagated
//}
// void combine(pnode& t,pnode l,pnode r){//combine segtree ranges
//     // t->val = 0;
//     // if(l) t->val += l->val;
//     // if(r) t->val += r->val;
//     if(!l || !r)return void(t = l?l:r);
// }
void operation(pnode t){//operation of segtree
    if(!t)return;
//    reset(t);//node represents single element of array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining l,r
    // combine(t, t->l, t->r);
    //combine(t,t->l,t);combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){//result/left/right array
    lazy(l);lazy(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);operation(t);
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior=rand();
    ret->size=1;
    ret->val=val;
    ret->l = NULL;
    ret->r = NULL;
    ret->lazy=0;
    return ret;
}

void range_update(pnode t,int l,int r, int val){//[l,r]

    // if(t->lazy)
    // {
    //     lazy(t);
    // }
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->lazy += val; //lazy_update
    merge(mid,L,t);merge(t,mid,R);
}

void insert(pnode &t, int l, int x)
{
    pnode L, R, mid;
    pnode xx = init(x);
    split(t, L, R, l);
    merge(mid, L, xx);
    merge(t, mid, R);
}

void print(pnode rr, int n)
{
    FOR(i,0,n-1)
    {
        if(i) printf(" ");
        pnode tmp;
        split(rr, tmp, rr, 0);
        printf("%d",tmp->val);
    }
    printf("\n");
}

pnode root;
vi v;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    srand(time(NULL));
    int n,m;
    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            int x;
            getI(x);
            pnode it = init(x);
            if(i==0) root = it;
            else merge(root, root, it);
        }

        getI(m);
        FOR(i,1,m)
        {
            int tt;
            getI(tt);

            if(tt==1)
            {
                int l,r,val;
                getIII(l,r,val);
                l--, r--;
                range_update(root, l, r, val);
            }
            else
            {
                int l,x;
                getII(l,x);
                l--;
                insert(root, l, x);
                n++;
            }

            //print(root, n);
        }

        FOR(i,0,n-1)
        {
            if(i) printf(" ");
            pnode tmp;
            split(root, tmp, root, 0);
            printf("%d",tmp->val);
        }
        printf("\n");
    }

    return 0;
}

