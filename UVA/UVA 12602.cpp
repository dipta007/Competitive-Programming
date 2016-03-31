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
    int N,d;
    char a,b,c;
    int ad=pow(26,2);
    int bd=26;
    int cd=1;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        getchar();
        scanf("%c%c%c-%d",&a,&b,&c,&d);
        int sum=((a-65)*ad+(b-65)*bd+(c-65)*cd);
        int re=abs(sum - d);
        if(re<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
}
