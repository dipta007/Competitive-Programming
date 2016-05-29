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

#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getI(a) 	     scanf("%d", &a)
#define PB(n) push_back(n)
#define    vi 	 vector < int >


#define M 1000000
bool marked[M];

bool isPrime(int n) {
  if (n < 2) return 1;
  if (n == 2) return 0;
  if (n % 2 == 0) return 1;
  return marked[n];
}

void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == 0) {
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = 1;
      }
    }
  }
}

vi v;
int n,k;
int dp[5][8000];

int call(int in,int we)
{
    if(in>k)
    {
        if(we==0) return 1;
        return 0;
    }
    int &ret = dp[in][we];
    if(ret!=-1) return ret;

    ret = 0;
    if(we-in>=0) ret += call(in,we-in);
    ret += call(in+1, we);

    return ret;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    sieve(64000);
    map <int, bool> mp;
    FOR(i,0,100)
    {
        FOR(j,0,100)
        {
            int k = i*i + j*j;
            if(k>8000) break;
            if(isPrime(k)==0 && mp[k]==0)
            {
                //debug(k)
                v.PB(k);
                mp[k]=1;
            }
        }
    }
    sort(v.begin(),v.end());
    //debug(v[1])
    FOR(ci,1,t)
    {
        getII(n,k);
        //cout << n << k << endl;
        SET(dp);
        printf("%d\n",call(1,v[n-1]));
    }

    return 0;
}



