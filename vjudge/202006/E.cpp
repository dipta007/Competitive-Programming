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

    int n,a,b;
    while( cin >> n >> a >> b )
    {
        a--;
        if(b<0)
        {
            b = -b;
            for(int i=a-1, k=1; k<=b; k++, i--)
            {
                if(i<0) i=n-1;
                if(i>=n) i=0;
                if(k==b) cout << i+1 << endl;
            }
        }
        else if(b>0)
        {
            for(int i=a+1, k=1; k<=b; k++, i++)
            {
                if(i<0) i=n-1;
                if(i>=n) i=0;
                if(k==b) cout << i+1 << endl;
            }
        }
        else cout << a+1 << endl;
    }

    return 0;
}


