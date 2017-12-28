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

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        double y=(n*n)/19.6;
        double k=0.0;
        int i;
        for(i=1;k<y;i++)
        {
            k=5.0*i-5.0;
        }
        printf("%d\n",i-1);
    }
}
