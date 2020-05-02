#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int l=(a^b^c);
    //l=(l^c)%1000000007;
    l=l%1000000007;
    cout << l;
}
