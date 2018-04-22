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

class HalvingEasy
{
public:
	int count(vector <int> S, int T)
    {
        int cnt = 0;
        for(int i=0; i<S.size(); i++)
        {
            int flg = 0;
        	int kk = S[i];
            while(kk!=0)
            {
                if(kk==T) flg = 1;
                kk /= 2;
            }
            if(flg) cnt++;

        }
        return cnt;
    }
}
