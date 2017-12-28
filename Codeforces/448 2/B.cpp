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

// int a[100004];

// int get(int l, int r, int x)
int get(int A, int B, int M)
{
    if(A > B) return -1;
    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
 
    // A is not divisible by M
    return (B / M) - (A / M);
}

int main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n,x,k;
    while(cin >> n >> x >> k)
    {
        // map <int, int> mp;
        vector < int > a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;

            a.push_back(x);
            //mp[x]++;
        }

        sort(a.begin(), a.end());

        long long cnt = 0;
        for(int i=0; i<n; i++)
        {
            int low = 0, high = n-1;
            int res = -1;
            while(low <= high)
            {
                int mid = (low + high) / 2;

                int kk = get(a[i], a[mid], x);
                if(kk >= k)
                {
                    if(kk==k) res = mid;
                    high = mid - 1;
                }
                else if(kk < k)
                {
                    low = mid + 1;
                }
            }

            int lft = res;

            low = 0, high = n-1;
            while(low <= high)
            {
                int mid = (low + high) / 2;

                int kk = get(a[i], a[mid], x);
                if(kk > k)
                {
                    high = mid - 1;
                }
                else if(kk <= k)
                {
                    if(kk==k) res = mid;
                    low = mid + 1;
                }
            }
            int rgt = res;

            if(lft==-1) continue;

            cout << i << " " << lft << " " << rgt << endl;
            cnt += (long long )(rgt - lft + 1);
        }

        cout << cnt << endl;
    }

    return 0;
}


