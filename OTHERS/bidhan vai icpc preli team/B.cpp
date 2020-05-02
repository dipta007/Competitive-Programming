#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,i,j,k,a[200],b[200],cnt;
    while(scanf("%d",&n)!=EOF)
    {
        map<int,int>mp;
        cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            if(a[i]!=b[i]&&mp[b[i]]==0)
            {
                mp[b[i]]=1;
            }
        }
        for(i=0;i<1002;i++)
        {
            if(mp[a[i]]==1)cnt++;
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}
