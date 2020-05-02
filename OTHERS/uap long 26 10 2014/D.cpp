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
#define    getL(n)           scanf("%lld",&n)
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


void computeLPSArray(string pat, int M, int *lps);
//int cnt;


bool KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();


//    int M = strlen(pat);
    int *lps = (int *)malloc(sizeof(int)*M);
    computeLPSArray(pat, M, lps);

    int j  = 0;  // index for pat[]
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
          //cnt++;
          return 1;
        //printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return 0;
}

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,q;
    while(~getII(n,q))
    {
        getchar();
        string s[n];
        for(int i=0;i<n;i++)
        {
            getline(cin,s[i]);
            //cout << s[i] <<endl;
        }


        for(int j=1;j<=q;j++)
        {
            string pat;
            getline(cin,pat);
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(KMPSearch(pat,s[i]))
                {
                    cnt++;
                    //debugI();

                }

            }
            //KMPSearch(pat,a);
            printf("%d\n",cnt);
        }
    }

    return 0;
}

//// Driver program to test above function
//int main()
//{
//   char *txt = "ABABDABACDABABCABAB";
//   char *pat = "ABABCABAB";
//   KMPSearch(pat, txt);
//   return 0;
//}



