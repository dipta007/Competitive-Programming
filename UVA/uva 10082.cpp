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



int main() {
    char n[100];

        gets(n);
        for(int i=0;i<strlen(n);i++)
        {
            if(n[i]=='e')
                n[i]='q';
            else if(n[i]=='r')
                n[i]='w';
            else if(n[i]=='t')
                n[i]='e';
            else if(n[i]=='y')
                n[i]='r';
            else if(n[i]=='u')
                n[i]='t';
            else if(n[i]=='i')
                n[i]='y';
            else if(n[i]=='o')
                n[i]='u';
            else if(n[i]=='p')
                n[i]='i';
            else if(n[i]=='[')
                n[i]='o';
            else if(n[i]==']')
                n[i]='p';
            else if(n[i]=='d')
                n[i]='a';
            else if(n[i]=='f')
                n[i]='s';
            else if(n[i]=='g')
                n[i]='d';
            else if(n[i]=='h')
                n[i]='f';
            else if(n[i]=='j')
                n[i]='g';
            else if(n[i]=='k')
                n[i]='h';
            else if(n[i]=='l')
                n[i]='j';
            else if(n[i]==';')
                n[i]='k';
            else if(n[i]==' ')
                n[i]='l';

        }
        puts(n);
    }

