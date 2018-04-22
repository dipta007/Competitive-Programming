#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st1, st2;
    cin >> st1 >> st2;

    reverse(st2.begin(), st2.end());

    if(st1 == st2) printf("YES\n");
    else printf("NO\n");
}
