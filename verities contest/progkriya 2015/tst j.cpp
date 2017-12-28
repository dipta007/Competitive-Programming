#include <iostream>
#include <vector>


int main ()
{
  std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);

  myvector.pop_back();
  for(int i=0;i<myvector.size();i++)
    std::cout<<myvector[i]<<"\n";
  return 0;
}
