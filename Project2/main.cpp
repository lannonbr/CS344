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

  //// Testing begin and end functions
  //cout << newMap.begin(newMap.top())->getValue() << '\n';
  //cout << newMap.end(newMap.top())->getValue() << '\n';

  // Testing swap function
  newMap.swap(3, 1);

  // Testing [] operator
  cout << newMap[3] << '\n';
  // cout << newMap[4] << '\n'; // Note: This will safely close the program for an invalid index

  // Erasing a node
  newMap.erase(2);

  cout << newMap[1] << '\n';

  // cout << newMap.find(newMap.top(), 1)->next() << '\n';

  Map<int, string> map2(newMap);
  cout << map2[1] << '\n';

  map2.insert(40, "Wat");

  cout << "Size of map1: " << newMap.size() << '\n';
  cout << "Size of map2: " << map2.size() << '\n';

  newMap.insert(402, "cats 4");
  newMap.insert(3002, "i am a cow");
  cout << "iterator start" << '\n';
  for (auto itr = newMap.begin(); itr != newMap.end(); ++itr) {
    cout << itr->second << '\n';
  }
  cout << "iterator end" << '\n';
  return 0;
}
