//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    SETI(ar)           memset(ar,126,sizeof ar)


#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
     #define debug(args...) {cerr<< __LINE__ << " D: "; dbg,args; cerr<<endl;}
     #define trace(...) { cerr << "Line " << __LINE__ << ": "; __f(#__VA_ARGS__, __VA_ARGS__); }
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');
            cerr.write(names, comma - names) << " : " << arg1<<" | ";
            __f(comma+1, args...);
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
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

#define MX 1000004
int arr[MX];

struct node {
	int size, prior;
    ll val; //value stored in the array
    ll sum; //whatever info you want to maintain in segtree for each node
    ll lazy; //whatever lazy update you want to do
    node *l, *r;
	node(){}
	node(int val) {
		size = 1;
		this->val = val;
		prior = rand();
        lazy = 0;
        sum = val;
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

void lazy(pnode t){
    if(!t || !t->lazy)return;

    /// Update the value of current subtree
    t->val += t->lazy;
    t->sum += t->lazy * sz(t);

    /// Propagate Lazy to the left and right subtree
    if(t->l) t->l->lazy += t->lazy;
    if(t->r) t->r->lazy += t->lazy;
    t->lazy=0;
}
void reset(pnode t){
   if(t)t->sum = t->val;//lazy already propagated
}
void combine(pnode& t,pnode l,pnode r){//combine segtree ranges
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum ;
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//node represents single element of array
    lazy(t->l);lazy(t->r); //imp:propagate lazy before combining l,r
    combine(t,t->l,t);combine(t,t,t->r);
}

void split(pnode t, pnode &l, pnode &r, int pos, int add=0){
    if(!t) return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
            split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else    split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){//result //left //right array
    lazy(l); lazy(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else                       merge(r->l,l,r->l),t=r;
    upd_sz(t); operation(t);
}

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
void print(pnode rr, int n)
{
    FOR(i,0,n-1)
    {
        if(i) cout << " ";
        pnode tmp;
        split(rr, tmp, rr, 0);
        cout << tmp->val;
    }
    cout << endl;
}
void clear_tree(pnode t)
{
    if(!t) return;
    clear_tree(t->l);
    clear_tree(t->r);
    free(t);
}

pnode findLess(pnode t, int val) {
	if(!t)            return NULL;
	trace(val, t->val);
	if(t->val < val) return t;
	if(val >= t->val) return findLess(t->l, val);
	else              return findLess(t->r, val);
}

pnode findGreater(pnode t, int val) {
//	if(!t)            return NULL;
//	if(val > t->val) return t;
//	else              return findGreater(t->l, val);
}

update(pnode p, int val)
{
    p->lazy += val;
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
    cout<<t->val << endl;;
    display(t->l, level + 1);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n, q;
        cin >> n >> q;
        FOR(i,0,n-1) cin >> arr[i];
        trace(n, q);
        initArray(n);
        display(root, 0);

        FOR(i,1,q)
        {
            int tt, x, y;
            cin >> tt >> x >> y;
            if(tt == 1)
            {
                update( findLess(root, x), -y );
            }
            else update( findGreater(root, x) , y );
        }

        print(root, n);
        clear_tree(root);
    }

    return 0;
}


