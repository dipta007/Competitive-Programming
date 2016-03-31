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
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int h,l;
        cin >> h >> l;
        for(int j=1;j<=l;j++)
        {
            for(int line=1;line<=h;line++)
            {
                for(int k=1;k<=line;k++)
                {
                    cout << line;
                }
                cout << endl;
            }
            for(int line=h-1;line>=1;line--)
            {
                for(int k=1;k<=line;k++)
                {
                    cout << line;
                }
                cout << endl;
            }
            if(i==t && j==l)
                ;
            else
                cout << endl;
        }
    }
}
