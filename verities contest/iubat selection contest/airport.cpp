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

int fact(int x)
{
    int c=1;
    for(int i=x;i>0;i--)
    {
        c=c*i;
    }
    cout << c <<endl;
    return c;
}

int main()
{

    char a[4],b[4],c[4];
    while(scanf("%s",a)!=EOF)
    {
        int cs=0,cb=0,cg=0;
        getchar();
        gets(b);
        gets(c);
        for(int i=0;i<3;i++)
        {
            if(a[i]=='*')
                cs++;
            if(a[i]=='B')
                cb++;
            if(a[i]=='G')
                cg++;
            if(b[i]=='*')
                cs++;
            if(b[i]=='B')
                cb++;
            if(b[i]=='G')
                cg++;
            if(c[i]=='*')
                cs++;
            if(c[i]=='B')
                cb++;
            if(c[i]=='G')
                cg++;
        }
        cout << cs <<endl << cb<<endl<<cg<<endl;
        int x;
        int za=9-cs-1;
        int x1=fact(za);
        int x2=fact(za-cb-1);
        int x3=x1/x2;
        int x4=fact(cb-1);
        int x5=x3/x4;
        int y2=fact(za-cg-1);
        int y3=x1/y2;
        int y4=fact(cg-1);
        int y5=y3/y4;
        if(cg==0)
            x=x5;
        else if(cb==0)
            x=y5;
        else
            x=x5+y5;
        printf("%d\n",x);
    }


}
