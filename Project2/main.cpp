#include <iostream>
#include "Map.h"
using std::string;
using std::cout;

int main() {

  // Creating the Map
  Map <int, string> newMap;

  // Testing empty function
  cout << "Empty: " << newMap.empty() << '\n';

  // Inserting a few items
  newMap.insert(3, "Lambda :D");
  newMap.insert(2, "Foobar");
  newMap.insert(1, "Cats");

  // Testing begin and end functions
  cout << newMap.begin(newMap.top())->getValue() << '\n';
  cout << newMap.end(newMap.top())->getValue() << '\n';

  // Testing swap function
  newMap.swap(3, 1);

  // Testing [] operator
  cout << newMap[3] << '\n';
  // cout << newMap[4] << '\n'; // Note: This will safely close the program for an invalid index

  // Erasing a node
  newMap.erase(2);

  cout << newMap[1] << '\n';

  return 0;
}
