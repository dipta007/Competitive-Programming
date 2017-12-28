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
   ios_base::sync_with_stdio(0);cin.tie(0);

    int n, k;
    while( ~ scanf("%d %d", &n, &k))
    {
        getchar();
        char st[10000004];
        for(int i=1;i<=n;i++)
        {
            gets(st);
        }
        printf("%d\n", k);
    }

    return 0;
}


