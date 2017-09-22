#include <iostream>
using namespace std;



#define MAX 100005
int bit[MAX];
void update ( int x, int v )
{
    while ( x < MAX )
    {
        bit[x] += v;
        x += x & (-x);
    }
}
int query ( int x )
{
    int res = 0;
    while ( x )
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}

// get largest value with cumulative sum less than or equal to x;
// for smallest, pass x-1 and add 1 to result
int getind(int x) {
    int LOGSZ = 17;
    int N = (1<<LOGSZ);
  int idx = 0, mask = N;
  while(mask && idx < N) {
    int t = idx + mask;
    if(x >= bit[t]) {
      idx = t;
      x -= bit[t];
    }
    mask >>= 1;
  }
  return idx;
}

///** 2d BIT
ll bit[1030][1030];
int arr[1030][1030];

void update ( int x, int y,int v )
{
    while ( x <= n )
    {
        int tmp=y;
        while(tmp<=n)
        {
            bit[x][tmp] += v;
            tmp += tmp & (-tmp);
        }
        x += x & (-x);
    }
}

ll query ( int x,int y)
{
    ll res = 0;
    while ( x )
    {
        int tmp=y;
        while(tmp)
        {
            res+=bit[x][tmp];
            tmp -= tmp & (-tmp);
        }
        x -= x & (-x);
    }
    return res;
}
