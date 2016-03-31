#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;


#define M 1000004
bool marked[M]={0};

void sieve(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (marked[i] == 0) {
      for (int j = i * i; j <= n; j += i) {
        marked[j] = 1;
      }
    }
  }
}


int main()
{
    int n;
    char a[100];
    sieve(1000001);
    while(scanf("%s",a)!=EOF)
    {
        n=atoi(a);
        int p=0,e=0;
//        if(marked[n]==0)
//            p=1;

        int s=strlen(a);
        int sum=0;
        for(int i=s-1;n!=0;i--)
        {
            int x;
            x=n%10;
            n=n/10;
            sum=sum+(x*pow(10,i));

        }
        cout << sum << endl;
    }
}
