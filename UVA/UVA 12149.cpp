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

int main()
{
    int N;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
            break;

        int sum=1;
        for(int i=2;i<=N;i++)
        {
            sum=sum + (i*i);
        }
        printf("%d\n",sum);
    }

}
