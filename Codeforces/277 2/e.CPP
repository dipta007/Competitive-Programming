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


const int mx=100004;
int n; // the number of items in the sequence
int Sequence[mx]; // the sequence of integers
int L[mx]; // L[] as described in the algorithm

void takeInput() {
    scanf("%d", &n); // how many numbers in the sequence ?

    // take the sequence
    for( int i = 0; i < n; i++ )
        scanf("%d", &Sequence[i]);
}

int LIS() { // which runs the LIS algorithm and returns the result
    int i, j; // auxilary variables for iteration

    // initialize L[] with 1
    for( i = 0; i < n; i++ )
        L[i] = 1;

    // start from the left most item and itetare right
    for( i = 0; i < n; i++ ) {
        // for the ith item item find all items that are in right
        for( j = i + 1; j < n; j++ ) {

            if( Sequence[j] > Sequence[i] ) {
                // the item is greater than the ith item

                // so, L[j] = L[i] + 1, since jth item can be added after ith
                // item. if L[j] is already greater than or equal to L[i] + 1
                // then ignore it
                if( L[j] < L[i] + 1 )
                    L[j] = L[i] + 1;
            }
        }
    }
    // now find the item whose L[] value is maximum
    int maxLength = 0;
    for( i = 0; i < n; i++ ) {
        if( maxLength < L[i]  )
            maxLength = L[i];
    }
    // return the result
    return maxLength;
}

int main() {
    takeInput();
    int result = LIS();
    int maxy=0;
    for(int i=0;i<n;i++)
    {
        printf("%d ",L[i]);
        if(L[i]==result) maxy++;
    }
    cout << endl;
    int res[n];
    CLR(res);
    for(int i=n-1;i>=0;i--)
    {
        if(L[i]==result)
        {
            int x=i;
            res[i]++;
            for(int j=x-1;j>=0;j--)
            {
                if( Sequence[j] < Sequence[x] && L[j] == L[x] - 1 ) {
                // we have found a valid item so, we will save it
                    x = j; // as in our algorithm
                    res[j]++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
    return 0;
}




//int main() {
//    //READ("in.txt");
//    //WRITE("out.txt");
//
//    takeInput();
//    int result = LisNlogK();
//    int res[n];
//    CLR(res);
//    int cnt=1;
//    for(int i=0;i<n;i++)
//    {
//        if(L[i]<cnt)
//        {
//            res[i]++;
//        }
//        else if(L[i]==cnt)
//        {
//            cnt++;
//            res[i]++;
//        }
//    }
//    return 0;
//}
//
//int main() {
//
//    return 0;
//}
