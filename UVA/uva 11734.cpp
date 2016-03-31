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
    int t,i,k;
    char team[24],judge[24];
    scanf("%d ",&t);
    for(i=1;i<=t;i++)
    {
        gets(team);
        gets(judge);
        k=strcmp(team,judge);
        if(k==0)
            cout << "Case " << i << ": Yes" << endl;
        else
        {
            if(strlen(team)>strlen(judge))
                cout << "Case " << i << ": Output Format Error" << endl;
            else
                cout << "Case " << i << ": Wrong Answer" << endl;
        }

    }
}

