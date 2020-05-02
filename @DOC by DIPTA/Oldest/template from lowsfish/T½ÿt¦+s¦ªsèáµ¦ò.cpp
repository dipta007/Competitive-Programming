#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a[500]={0},b[500]={0},ans[501]={0},x,i,lena,lenb,t;
    char a1[501],b1[501];
    cin>>a1;
    cin>>b1;
    lena=strlen(a1);
    lenb=strlen(b1);
    for(i=0;i<lena;++i) a[i]=a1[i]-'0';
    for(i=0;i<lenb;++i) b[i]=b1[i]-'0';
    t=0;
    while(t<=lena||t<=lenb)
    {
                           ans[t]+=a[lena-t-1]+b[lenb-t-1];
                           if(ans[t]>=10) 
                           {
                                          ans[t+1]++;
                                          ans[t]%=10;
                                          }
                           ++t;
                           }
    --t;
    if(ans[t]==0) t--;
    for(;t>=0;--t) cout<<ans[t];
    cin.get();
    cin.get();
    return 0;
}
