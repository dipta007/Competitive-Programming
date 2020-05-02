#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a1[500],b1[500];
    int a[500],b[500],c[1000],lena,lenb,lenc,x,i,j;
    cin.getline(a1,500);
    cin.getline(b1,500);
    lena=strlen(a1);
    lenb=strlen(b1);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=0;i<lena;++i) a[lena-i]=a1[i]-'0';
    for(i=0;i<lenb;++i) b[lenb-i]=b1[i]-'0';
    for(i=1;i<=lena;++i)
    {
       x=0;
       for(j=1;j<=lenb;++j)
       {
        c[i+j-1]+=a[i]*b[j]+x;
        x=c[i+j-1]/10;
        c[i+j-1]%=10;
                           }
       c[i+lenb]=x;
           
    }
    lenc=lena+lenb;
    for(;lenc>=1&&c[lenc]==0;--lenc);
    for(;lenc>=1;--lenc)    cout<<c[lenc];
    getchar();
    getchar();
    return 0;
} 
