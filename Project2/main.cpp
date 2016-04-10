#include <iostream>
#include "Map.h"
using namespace std;

int main(int argc, char ** argv) {
  Map <int, string> newMap;
  newMap.insert(3, "Lambda :D");
  newMap.insert(2, "Foobar");
  cout << newMap.min()->getValue() << '\n';
  cout << newMap.max()->getValue() << '\n';
  cout << newMap[4];
  return 0;
}
