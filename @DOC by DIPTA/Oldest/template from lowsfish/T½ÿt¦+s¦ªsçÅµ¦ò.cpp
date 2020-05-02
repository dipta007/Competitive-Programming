#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool j(char a[],char b[])
{
     int i;
     if(strlen(b)>strlen(a))return 0;
     if(strlen(b)<strlen(a))return 1;
     for(i=0;i<strlen(a);++i) if(a[i]<b[i]) return 0;
     return 1;
     }
int main()
{
    char a1[501],b1[501],c[500];
    int a[500]={0},b[500]={0},ans[500]={0},i,lena,lenb,t;
    cin>>a1;
    cin>>b1;
    t=0;
    if(!j(a1,b1)) {
           cout<<'-';
           strcpy(c,a1);
           memset(a1,'\0',sizeof(a1));
           strcpy(a1,b1);
           memset(b1,'\0',sizeof(b1));
           strcpy(b1,c);
           }
    lena=strlen(a1);
    lenb=strlen(b1);

    for(i=0;i<lena;++i) a[i]=a1[i]-'0';
    for(i=0;i<lenb;++i) b[i]=b1[i]-'0';
    while(t<=lena||t<=lenb)
    {
                           if(a[lena-t-1]<b[lenb-t-1])
                            {
                                                      --a[lena-t-2];
                                                      a[lena-t-1]+=10;
                                                      }
                           ans[t]=a[lena-t-1]-b[lenb-t-1];
                           ++t;
                           }
    for(;ans[t]==0&&t>0;--t);
    for(;t>=0;--t) cout<<ans[t];
    cin.get();
    cin.get();
    return 0;
}
