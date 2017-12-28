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
        stack <int> a,b;
        scanf("%d",&n);
        if(n==0)
            break;

        for(int i=n;i>0;i--)
            a.push(i);
        int i=1;
        printf("Discarded cards:");
        while(1)
        {
            if(n==1){
                printf("\nRemaining card: 1\n");
                break;}
            while(!a.empty())
            {
                if(i%2==1)
                {
                    if(i==1)
                        printf(" ");
                    else if(!a.empty())
                        printf(", ");
                    printf("%d",a.top());
                    a.pop();
                }
                else{
                    b.push(a.top());
                    a.pop();}

                    i++;
            }
            int cnt=0;
            while(!b.empty())
            {
                a.push(b.top());
                b.pop();
                cnt++;
            }
            if(cnt==1)
            {
                printf("\nRemaining card: %d\n",a.top());
                a.pop();
                break;
            }
        }
    }
}
