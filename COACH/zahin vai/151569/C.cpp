#include <bits/stdc++.h>
using namespace std;

#define M 10000004
bool marked[M];
vector <int> primes;

void sieve(int n) {
	primes.push_back(2);
	for (long long i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			for (long long j = i * i; j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }
  for(int i=4;i<=n;i+=2) marked[i]=1;
  for(int i=3;i<=n;i+=2)
  {
      if(marked[i]==0) primes.push_back(i);
  }
}


int meu[10000004];
long long res=0;
long long n;
vector <long long> v;

int main() {
    #ifdef dipta007
//        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve(M-2);
    int t;
    cin >> t;
    v.push_back(1);
    for(int i=0;i<=primes.size()-1;i++)
    {
        if(primes[i]>10000000) break;
        v.push_back(primes[i] * primes[i]);
    }
    for(int i=1;i<=10000000;i++)
    {
        meu[i]=1;
    }
    for(int k=2;k<=10000000;k++)
    {
        int i = k;
        if(marked[i]==0)
        {
            for(long long j=i;j<=10000000; j+=i)
            {
                meu[j] *= -1;
            }
            long long kk = i*1LL*i;
            for(long long j=kk;j<=10000000LL;j+=kk)
            {
                meu[(int)j] = 0;
            }
        }
    }
    for(int ci=1;ci<=t;ci++)
    {
        cin >> n;
        res=0;
        long long nn = sqrt(n);
        for(int i=1;i<=nn;i++)
        {
            //if(v[i]>n) break;
            //debug(i,v[i],meu[v[i] ])
            res += n/((long long)i*i) * meu[ i ];
        }
        printf("%lld\n",res);
    }

    return 0;
}



