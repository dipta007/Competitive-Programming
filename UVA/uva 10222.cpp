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
    char a[100];
    while(gets(a))
    {
        int s=strlen(a);
        for(int i=0;i<s;i++)
        {
            if(a[i]=='e' || a[i]=='E')
                a[i]='q';
            else if(a[i]=='r' || a[i]=='R')
                a[i]='w';
            else if(a[i]=='t' || a[i]=='T')
                a[i]='e';
            else if(a[i]=='y' || a[i]=='Y')
                a[i]='r';
            else if(a[i]=='u' || a[i]=='U')
                a[i]='t';
            else if(a[i]=='i' || a[i]=='I')
                a[i]='y';
            else if(a[i]=='O' || a[i]=='o')
                a[i]='u';
            else if(a[i]=='P' || a[i]=='p')
                a[i]='i';
            else if(a[i]=='[' || a[i]=='{')
                a[i]='o';
            else if(a[i]==']' || a[i]=='}')
                a[i]='p';
            else if(a[i]=='d' || a[i]=='D')
                a[i]='a';
            else if(a[i]=='f' || a[i]=='F')
                a[i]='s';
            else if(a[i]=='g' || a[i]=='G')
                a[i]='d';
            else if(a[i]=='h' || a[i]=='H')
                a[i]='f';
            else if(a[i]=='j' || a[i]=='J')
                a[i]='g';
            else if(a[i]=='k' || a[i]=='K')
                a[i]='h';
            else if(a[i]=='l' || a[i]=='L')
                a[i]='j';
            else if(a[i]==';' || a[i]==':')
                a[i]='k';
            else if(a[i]=='\'' || a[i]=='"')
                a[i]='l';
            else if(a[i]=='c' || a[i]=='C')
                a[i]='z';
            else if(a[i]=='v' || a[i]=='V')
                a[i]='x';
            else if(a[i]=='b' || a[i]=='B')
                a[i]='c';
            else if(a[i]=='n' || a[i]=='N')
                a[i]='v';
            else if(a[i]=='m' || a[i]=='M')
                a[i]='b';
            else if(a[i]==',' || a[i]=='<')
                a[i]='n';
            else if(a[i]=='.' || a[i]=='>')
                a[i]='m';
        }
        puts(a);
    }
}
