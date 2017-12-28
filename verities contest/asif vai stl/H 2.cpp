#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


int main()
{

    int n;
    while(1)
    {
        queue <int> a,b;
        scanf("%d",&n);
        if(n==0)
            break;

        for(int i=1;i<=n;i++)
            a.push(i);
        int i=1;
        printf("Discarded cards:");
        while(1)
        {
            int cnt=0;
            if(n==1)
            {
                printf("\nRemaining card: 1\n");
                break;
            }
            while(!a.empty())
            {
                if(i%2==1)
                {
                    if(!a.empty())
                        printf(" ");
                    printf("%d",a.front());
                    a.pop();
                }
                else{
                    b.push(a.front());
                    a.pop();
                    cnt++;}

                i++;
            }
            if(cnt==1)
            {
                printf("\nRemaining card: %d\n",b.front());
                b.pop();
                break;
            }
            cnt=0;
            while(!b.empty())
            {
                if(i%2==1)
                {
                    if(!b.empty())
                        printf(" ");
                    printf("%d",b.front());
                    b.pop();
                }
                else{
                    a.push(b.front());
                    b.pop();
                    cnt++;}

                i++;
            }
            if(cnt==1)
            {
                printf("\nRemaining card: %d\n",a.front());
                a.pop();
                break;
            }
        }
    }
}

