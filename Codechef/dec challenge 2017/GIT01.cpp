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

    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        int n,m;
        cin >> n >> m;
        string st = "RG";

        string mat[n];
        for(int i=0; i<n; i++)
        {
            cin >> mat[i];
        }

        int cnt1 = 0, cnt2 = 0;

        int flg = 0;
        for(int i=0; i<n; i++)
        {
            int now = flg;
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] != st[now])
                {
                    if(mat[i][j] == 'R') cnt1 += 5;
                    else cnt1 += 3;
                }
                now = now ^ 1;
            }
            flg = flg ^ 1;
        }

        flg = 1;
        for(int i=0; i<n; i++)
        {
            int now = flg;
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] != st[now])
                {
                    if(mat[i][j] == 'R') cnt2 += 5;
                    else cnt2 += 3;
                }
                now = now ^ 1;
            }
            flg = flg ^ 1;
        }

        cout << min(cnt1, cnt2) << endl;
    }

    return 0;
}


