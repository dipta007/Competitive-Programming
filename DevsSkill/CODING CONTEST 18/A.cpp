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


int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    for(int ci=1; ci<=t;ci++)
    {
        long long  init, last, n;
        cin >> init >> last >> n;

        int flg = 1;
        for(int i=0; i<n; i++)
        {
            string st;
            long long c;
            cin >> st >> c;
            if(st[0]=='o')
            {
                init -= c;
            }
            else init += c;

            if(init < 0) flg = 0;
        }

        if(init != last) flg =0;
        if(flg) printf("yes\n");
        else printf("no\n"); 
    }

    return 0;
}


