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
    int n;
    scanf("%d ",&n);
    for(int i=1;i<=n;i++)
    {
        char s[10000];
        scanf("%s",s);
        int ss=strlen(s);
        int k=atoi(s);
        if((ss==1 || ss==2) && (k==1 || k==4 || k==78))
        {
                printf("+\n");
        }
        else if(s[ss-2]=='3' && s[ss-1]=='5')
            printf("-\n");
        else if(s[0]=='9' && s[ss-1]=='4')
            printf("*\n");
        else if(s[0]=='1' && s[1]=='9' && s[2]=='0')
            printf("?\n");
    }
}
