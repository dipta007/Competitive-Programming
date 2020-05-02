#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

string nextGreater(string num) 
{ 
    int l = num.size(); 
    int i;
    for (i=l-1; i>=0; i--) 
    {
        if (num.at(i) == '0') 
        { 
            num.at(i) = '1'; 
            break; 
        }
        else
            num.at(i) = '0'; 
    }
    if (i < 0) 
        num = "1" + num;
    return num; 
} 

string sum(vector <string> arr) {
  string carry = "0";
  string res = "";
  for (int i = arr[0].size() - 1; i>=0; i--) {
    for(int j=0; j<arr.size(); j++) {
      string st = arr[j];
      if (st[i] == '1') {
        carry = nextGreater(carry);
      }
    }
    res = carry.back() + res;
    carry.pop_back();
    if (carry.size() == 0) carry = "0";
  }
  if (carry != "0") res = carry + res;
  return res;
}

int main() {
  vector <string> vs;
  vs.push_back("0");
  vs.push_back("0");
  vs.push_back("0");
  vs.push_back("0");
  cout << sum(vs) << endl;
}