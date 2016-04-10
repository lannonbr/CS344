#include <iostream>
#include "Map.h"
using namespace std;

int main(int argc, char ** argv) {

  // Creating the Map
  Map <int, string> newMap;

  // Testing empty function
  cout << newMap.empty() << '\n';

  // Inserting a few items
  newMap.insert(3, "Lambda :D");
  newMap.insert(2, "Foobar");

  // Testing min and max functions
  cout << newMap.min()->getValue() << '\n';
  cout << newMap.max()->getValue() << '\n';

  // Testing [] operator
  cout << newMap[3];
  cout << newMap[4]; // Note: This will safely close the program for an invalid index

  return 0;
}
