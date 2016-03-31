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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


bool cmp(const int &a,const int &b)
{
    if(abs(a)<abs(b)) return true;
    else return false;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,p;
    while(~getII(n,p))
    {
        int flg;
        if(p<=(n/2)) flg=1;
        else flg=2;

        p--;
        getchar();
        char st[n+4];
        gets(st);



        vector <int> v;
        int sum=0;
        for(int i=0,j=n-1;i<n/2;i++,j--)
        {
            if(st[i]!=st[j])
            {
                //int kmin(abs('a'-st[i]),abs('z'-st))
                //cout << st[i] << " " <<st[j] <<endl;
                //debugI();

                if(flg==1)
                {
                    v.PB(i);
                    int k=st[i]-st[j];
                    k=abs(k);
                    sum+=min(k,abs(26-k));
                }
                else
                {
                    v.PB(j);
                    int k=st[j]-st[i];
                    k=abs(k);
                    sum+=min(k,abs(26-k));
                }
            }
        }
        //debug(sum);
        vector <int> kasa;
        priority_queue <int,greater <1 > > kasa,dur;
        for(int i=0;i<v.size();i++)
        {
            kasa.push(v[i]-p);

        }

        //int sum=0;
        for(int i=0;i<kasa.size();i++)
        {
             //sort(ALL(kasa),cmp);
             int x=kasa.top();
             kasa.pop();
//             for(int j=0;j<kasa.size();j++)
//             {
//                 if(kasa[j]!=0)
//                 {
//                     x=kasa[j];
////                     cout << x << " ";
//                     break;
//                 }
//             }
//             cout << endl;
             sum=sum+abs(x);
             for(int j=0;j<kasa.size();j++)
             {
                 int l=kasa.top();
                 kasa.pop();

                 dur.push(l-x);
//                 if(kasa[j]!=0)
//                 {
//                     kasa[j]=kasa[j]-x;
//
//                 }
             }

        }
        printf("%d\n",sum);
    }

    return 0;
}






