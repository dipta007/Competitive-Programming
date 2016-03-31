/*
ID: iamdipt1
PROG: ride
LANG: C++
*/
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    char c[7],g[7];
    fin >>c >>g;
    int co=1,gr=1;
    int cs,gs;
    cs=strlen(c);
    for(int i =0;i<cs;i++)
    {
        co=co*(c[i]-64);
    }
    gs=strlen(g);
    for(int i =0;i<gs;i++)
    {
        gr=gr*(g[i]-64);
    }
    co=co%47;
    gr=gr%47;
    if(co==gr)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;


    return 0;
}

