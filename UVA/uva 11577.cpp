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
    int n,m;
    scanf("%d ",&n);
    char a[220];
    int cnt[28];
    while(n--)
    {
        memset(cnt,0,sizeof(cnt));
        gets(a);
        int sa=strlen(a);
        for(int i=0;i<sa;i++)
        {
            if(a[i]>='a' && a[i]<='z')
            {
                int k=a[i]-97;
                cnt[k]++;
            }
            else if(a[i]>='A' && a[i]<='Z')
            {
                int k=a[i]-65;
                cnt[k]++;
            }
        }
        m=0;
        for(int i=0;i<26;i++)
        {
            m=max(m,cnt[i]);
        }
        for(int i=0;i<26;i++)
        {
            if(m==cnt[i])
                printf("%c",i+97);
        }
        printf("\n");
    }
}
