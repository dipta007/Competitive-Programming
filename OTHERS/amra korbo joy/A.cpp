#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
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
#include <math.h>

int main()
{

        vector < int > a;
        int i=0;
        int n;
        while(1)
        {
            scanf("%d",&n);
            if(n==42)
                break;
            i++;
            a.push_back(n);

        }
        sort(a.begin(),a.end());
        for(int j=0;j<i;j++)
            printf("%d\n",a[j]);

}
