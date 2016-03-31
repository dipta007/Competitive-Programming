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

char arr[]={'a','b','a'};
vector<char>result;
int taken[20]={0};


void call()
{
	if(result.size()==3)
	{
		for(int i=0;i<3;i++)
		printf("%c",result[i]);
		puts("");
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(taken[i]==0)
		{
			taken[i]=1; result.push_back(arr[i]);
			call();
			taken[i]=0; result.pop_back();
		}
	}
}
int main()
{

	call();
}
