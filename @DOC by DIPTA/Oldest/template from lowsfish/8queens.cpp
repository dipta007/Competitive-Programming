#include<iostream>
#include<cstdio>
using namespace std;
int a[8],tot=0;const int n=8;
void work(int line)
{
    int i,j;
    if(line==n) tot++;
    else 
    for(i=0;i<n;++i)
    {
        bool ok=1;
        a[line]=i;
        for(j=0;j<line;++j)
            if(a[line]==a[j]||a[line]-line==a[j]-j||a[line]+line==a[j]+j)
            {
               ok=0;
               break;
            }
        if(ok)
         work(line+1);
    }
}
int main()
{

    work(0);
    cout<<tot;
    return 0;
}
