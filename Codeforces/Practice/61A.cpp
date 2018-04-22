#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st1, st2;
    cin >> st1 >> st2;

    string tmp = "";
    for(int i=0; i< (int)st1.size(); i++)
    {
        int k1 = st1[i] - '0';
        int k2 = st2[i] - '0';

        if(k1 == k2) tmp += "0";
        else tmp += "1";
    }
    cout << tmp << endl;
}

