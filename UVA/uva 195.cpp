#include <algorithm>
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

#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FF(i,L,R) for (int i = L; i <= R; i++)
#define FR(i,L,R) for (int i = L; i > R; i--)
#define FRF(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(p) p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)

#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector < int >
#define vii vector < vector < int > >

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define PI 3.1415926535897932384626

int alph_ord(char c)
{
   if(isupper(c))
   {
      return (c-'A')*2;
   }
   else
   {
      return (c-'a')*2+1;
   }
}
bool cmp1(const char &a,const char &b)
{
   return alph_ord(a) < alph_ord(b);
}

//char arr[]={'a','b','c','d'};
vector<char>result;
int taken[100004],len;
map <string,int> mp;
string a;

void call()
{
	if(result.size()==len)
	{
	    string stt;
		for(int i=0;i<len;i++)
            stt+=result[i];
            debug(stt);
        if(mp[stt]==0)
        {
            printf("%s\n",stt.c_str());
            mp[stt]=1;
        }
		//puts("");
		return;
	}
	for(int i=0;i<len;i++)
	{
		if(taken[i]==0)
		{
			taken[i]=1; result.push_back(a[i]);
			call();
			taken[i]=0; result.pop_back();
		}
	}
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    scanf("%d ",&n);
    for(int ci=1;ci<=n;ci++)
    {
        getline(cin,a);
        len=a.size();
        for(int i=0;i<=len;i++)
            taken[i]=0;
        sort(ALL(a),cmp1);
        call();
    }
    return 0;
}

