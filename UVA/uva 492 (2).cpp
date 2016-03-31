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
    char a[100],b[100];
    while(gets(a))
    {
        int l=0;
        int s=strlen(a);
        for(int i=0;i<s;i++)
        {
            if(i==0)
            {
                if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
                {
                    for(int j=0;;j++)
                    {
                        if(a[j]==' ')
                        {
                            b[l++]='a';
                            b[l++]='y';
                            break;
                        }
                        else
                            b[l++]=a[j];
                    }
                }
                else
                {
                    for(int j=1;;j++)
                    {
                        if(a[j]==' ')
                        {
                            b[l++]=a[0];
                            b[l++]='a';
                            b[l++]='y';
                            break;
                        }
                        else
                            b[l++]=a[j];
                    }
                }
            }

        }
        b[l]=NULL;
        cout << b << endl;
    }
}
