#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a1[500];
    int i,j,a[500]={0},c[500]={0},x,d,len;
    cin.getline(a1,500);
    cin>>x;
    len=strlen(a1);
    for(i=0;i<len;++i) a[i]=a1[i]-'0';          //非倒序
    for(i=0;i<len;++i)
    {
        d=d*10+a[i];
        c[i]=d/x;
        d%=x;
    }
    for(i=0;c[i]==0&&i<len;++i);
    for(;i<len;++i) cout<<c[i];
    return 0;
}
