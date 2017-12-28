#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
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


// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

int main() {

    int n;
    while(~scanf("%d", &n))
    {
        int a[n+n];
        int sum = 0;
        for(int i=0; i<n;i ++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        for(int i=n; i<n+n; i++)
        {
            a[i] = a[i-n];
        }

        int mini = INT_MAX;
        for(int i=0;i<n+n;i++)
        {
            int aa = 0;
            for(int j=i; j<i+n; j++)
            {
                aa += a[j];
                int bb = sum - aa;
                mini = min(mini, abs(bb-aa));
            }
        }
        printf("%d\n", mini);
    }

    return 0;
}


