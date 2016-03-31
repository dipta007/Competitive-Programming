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
    int T;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        int g,l;
        cin >> g >> l;
        if(l%g ==0)
            cout << g <<" "<<l<<endl;
        else
            cout << "-1"<<endl;
    }
}
