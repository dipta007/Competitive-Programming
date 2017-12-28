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

    string st;
    while(cin >> st)
    {
        int flg = 0;
        int c1 = 0, c2 = 0;
        for(int i=0; i<20; i++)
        {
            int kk = st[i] - '0';
            if(i%2==0) c1 += kk;
            else c2 += kk;


            if(i<10)
            {
                int baki = 10 - i - 1;
                int b1 = baki / 2;
                int b2 = baki / 2 + (i%2==0);
                //cout << baki << " " << b1 << " " << b2 << endl;
                if(c1 > c2 + b2)
                {
                    cout << "TEAM-A " << i+1 << endl;
                    flg = 1;
                    break;
                }
                else if(c2 > c1 + b1)
                {
                    cout << "TEAM-B " << i+1 << endl;
                    flg = 2;
                    break;
                }
            }
            else if(i%2==1)
            {
                if(c1 > c2)
                {
                    cout << "TEAM-A " << i+1 << endl;
                    flg = 1;
                    break;
                }
                else if(c2 > c1)
                {
                    cout << "TEAM-B " << i+1 << endl;
                    flg = 2;
                    break;
                }
            }
        }

        if(flg == 0)
        {
            cout << "TIE" << endl;
            flg = 1;        }
    }

    return 0;
}


