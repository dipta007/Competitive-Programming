
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
        int n;
        cin >> n;
        int a[n], sa[n], sba[n];

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            sa[i] = a[i];
            sba[i] = a[i];
        }

        sort(sa, sa+n);
        sort(sba, sba+n);
        reverse(sba, sba+n);


        //cout << n << endl;
        if(n==1)
        {
            cout << 0 << endl;
            cout << a[0] << endl;
            continue;
        }
        else if(n==2)
        {
            if(a[0] == a[1]) cout << 0 << endl;
            else cout << 2 << endl;
            cout << a[1] << " " << a[0] << endl;
            continue;
        }
        else if(n==3)
        {
            if(a[0]==a[1])
            {
                cout << 2 << endl;
                cout << a[2] << " " << a[0] << " " << a[1] << endl;
            }
            else if(a[1] == a[2])
            {
                cout << 2 << endl;
                cout << a[1] << " " << a[0] << " " << a[2] << endl;
            }
            else
            {
                if(a[0] == a[2]) cout << 2 << endl;
                else cout << 3 << endl;
                cout << a[2] << " " << a[0] << " " << a[1] << endl;
            }
            continue;
        }

        cout << n << endl;
        int in = 0;
        for(int i=0; i<n; i++)
        {
            if(sa[i]==sba[i])
            {
                swap(sba[i], sba[in]);
                in = n-1;
            }
        }

        map < int, int > mp1, mp2;
        for(int i=0; i<n; i++)
        {
            if(mp1[sa[i]] != 0)
            {
                mp2[sa[i]] = sba[i];
                continue;
            }
            mp1[ sa[i] ] = sba[i];
        }

        int b[n];
        for(int i=0; i<n; i++)
        {
            if(mp1[a[i]]==0)
            {
                b[i] = mp2[a[i]];
                continue;
            }
            b[i] = mp1[ a[i] ];
            mp1[ a[i] ] = 0;
        }

        for(int i=0; i<n; i++)
        {
            if(i) cout << " ";
            cout << b[i];
        }
        cout << endl;
    }

    return 0;
}


