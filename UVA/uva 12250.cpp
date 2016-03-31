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
    int l=0;
    char a[8][20]={"HELLO" , "HOLA" , "HALLO" , "BONJOUR" , "CIAO" , "ZDRAVSTVUJTE"};
    while(1)
    {
        char b[100];
        cin >> b;
        if(b[0]=='#' && strlen(b)==1)
            break;
        else if(!strcmp(b,a[0]))
            printf("Case %d: ENGLISH\n",++l);
        else if(!strcmp(b,a[1]))
            printf("Case %d: SPANISH\n",++l);
        else if(!strcmp(b,a[2]))
            printf("Case %d: GERMAN\n",++l);
        else if(!strcmp(b,a[3]))
            printf("Case %d: FRENCH\n",++l);
        else if(!strcmp(b,a[4]))
            printf("Case %d: ITALIAN\n",++l);
        else if(!strcmp(b,a[5]))
            printf("Case %d: RUSSIAN\n",++l);
        else
            printf("Case %d: UNKNOWN\n",++l);
    }
}
