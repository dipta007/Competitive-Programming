#include <algorithm>
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

string whatTime(int seconds)
{
    int h,m,s;
    h=seconds/3600;
    m=seconds%3600;
    m=m/60;
    s=(seconds%3600)%60;
    stringstream ss1,ss2,ss3;
    ss1 << h;
    string fs,s1,s2,s3;
    s1=ss1.str();
    fs=s1+":";
    ss2 << m;
    s2=ss2.str();
    fs=fs+s2;
    fs=fs+":";
    ss3 << s;
    s3=ss3.str();
    fs=fs+s3;
    return fs;
}

int main() {
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        printf("%s\n",whatTime(n).c_str());
    }
}
