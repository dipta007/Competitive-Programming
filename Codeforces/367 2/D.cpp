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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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



//bool search(char *str,int len)			// parameter = word & length of word
//{
//    node *curr=root;
//    for(int i=0; i<len; i++)
//    {
//        int id=str[i]-'a';
//        if(curr->next[id]==NULL) return false;
//        curr=curr->next[id];
//    }
//    return curr->endmark;				// jodi word thake then 1 return korbe
//										// jodi word na thake dn 0 return korbe
//}


struct node
{
    int endmark;
    int koita;
    node *next[2];
    node()
    {
        endmark=0;
        koita=0;
        for(int i=0; i<2; i++)
			next[i]=NULL;
    }
}*root;


void insert(string str,int len)			// parameter = word & length of word
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        curr->koita++;
    }
    curr->endmark++;

}

void del(node *cur)						// parameter hisebe root pathate hbe
{
    for(int i=0; i<2; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}

void del1(string str,int len)			// parameter = word & length of word
{
    node *curr=root;
    node *prev;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        prev=curr;
        curr=curr->next[id];
        curr->koita--;
//        debug(curr->koita,id)
//        if(curr->koita==0)
//        {
//            prev->next[id]=NULL;
////            del(prev->next[id]);
////            curr=NULL;
//            break;
//        }
    }
//    if(curr && curr->endmark>0)
//    {
//        curr->endmark--;
//    }
}


string dfs(string str, int len)
{
    node *curr=root;
    string xorr = "";
    FOR(i,0,len-1)
    {
        //debug(str[i],"*",curr->next[0])
        if(str[i]=='0' && curr->next[1] && curr->next[1]->koita>0)
        {
            xorr += '1';
            curr = curr->next[1];
        }
        else if(str[i]=='1' && curr->next[0] && curr->next[0]->koita>0)
        {
            xorr += '0';
            curr = curr->next[0];
        }
        else if(str[i]=='1' && curr->next[1] && curr->next[1]->koita>0)
        {
            xorr += '1';
            curr = curr->next[1];
        }
        else if(str[i]=='0' && curr->next[0] && curr->next[0]->koita>0)
        {
            xorr += '0';
            curr = curr->next[0];
        }
        else break;
    }
    return xorr;
}

string binary(int x)
{
    string st = "";
    while(x)
    {
        int k = x%2;
        x/=2;
        st += (char)(k+'0');
    }
    while(st.size()!=31)
    {
        st += "0";
    }
    reverse(ALL(st));
    return st;
}

ll binToDec(string x)
{
    ll res = 0;
    ll c = 1;
    ROF(i,(int)x.size()-1,0)
    {
        int k = x[i] - '0';
        res += (k*c);
        c *= 2;
    }
    return res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n;
    while(~getI(n))
    {
        root = new node();
        insert("0000000000000000000000000000000",31);
        FOR(i,0,n-1)
        {
            getchar();
            char ch;
            int x;
            scanf("%c %d",&ch,&x);
            if(ch=='+')
            {
                string xx = binary(x);
                debug(x,xx)
                insert(xx, xx.size());
            }
            else if(ch=='-')
            {
                string xx = binary(x);
                del1(xx, xx.size());
            }
            else
            {
                string xx = binary(x);
                string zz = dfs(xx, xx.size());
                debug(zz,binToDec(zz))
                printf("%lld\n",x^binToDec(zz));
            }
        }
        del(root);
    }

    return 0;
}



