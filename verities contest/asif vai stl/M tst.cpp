// map::find
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it=mymap.find('b');
  //std::cout << *it;
  mymap.erase (it);
  mymap.erase (mymap.find('d'));

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('f')->first<< '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';

  return 0;
}
