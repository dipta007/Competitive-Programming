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
    int t;
    char team[24],judge[24];
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> team;
        cin >> judge;
        k=strcmp(team,judge);
        if(k>0)
            cout << "Case " << i << ": Output Format Error" << endl;
        else if(k==0)
            cout << "Case " << i << ": Yes" << endl;
        else
            cout << "Case " << i << ": Wrong Answer" << endl;
    }
