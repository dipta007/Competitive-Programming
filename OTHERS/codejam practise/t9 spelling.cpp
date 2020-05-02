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
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
#define PI 3.1415926535897932384626

int main() {
    READ("in.in");
    WRITE("out.in");

    int n;
    map < char , int > msg;
    msg['a']=2;
    msg['b']=22;
    msg['c']=222;
    msg['d']=3;
    msg['e']=33;
    msg['f']=333;
    msg['g']=4;
    msg['h']=44;
    msg['i']=444;
    msg['j']=5;
    msg['k']=55;
    msg['l']=555;
    msg['m']=6;
    msg['n']=66;
    msg['o']=666;
    msg['p']=7;
    msg['q']=77;
    msg['r']=777;
    msg['s']=7777;
    msg['t']=8;
    msg['u']=88;
    msg['v']=888;
    msg['w']=9;
    msg['x']=99;
    msg['y']=999;
    msg['z']=9999;
    msg[' ']=0;
    scanf("%d",&n);
    getchar();

    for(int C=1;C<=n;C++)
    {
        string s1;

        getline(cin,s1);
        int l=s1.size();
        printf("Case #%d: ",C);
        for(int i=0;i<l;i++)
        {
            if(i>0 && msg[s1[i]]%10==msg[s1[i-1]]%10)
            {
                printf(" %d",msg[s1[i]]);
            }
            else
            {
                printf("%d",msg[s1[i]]);
            }
        }
        printf("\n");
    }
    return 0;
}

