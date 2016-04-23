#include <iostream>
#include "Map.h"
using std::string;
using std::cout;

int main() {

  // Creating the Map
  Map <int, string> newMap;

  // Testing empty function
  cout << "Empty: " << newMap.empty() << '\n';
  cout << "Inserting (3, \"Lambda :D\")" << '\n';
  // Inserting a few items
  newMap.insert(3, "Lambda :D");
  cout << "Inserting (2, \"Foobar\")" << '\n';
  newMap.insert(2, "Foobar");
  cout << "Inserting (1, \"Cats\")" << '\n';
  newMap.insert(1, "Cats");

  //// Testing begin and end functions
  //cout << newMap.begin(newMap.top())->getValue() << '\n';
  //cout << newMap.end(newMap.top())->getValue() << '\n';

  // Testing swap function
  cout << "Swapping 3 and 1." << '\n';
  newMap.swap(3, 1);

  // Testing [] operator
  cout << "Value at key 3: ";
  cout << newMap[3] << '\n';
  cout << "Value at key 1: ";
  cout << newMap[1] << '\n';
  // cout << newMap[4] << '\n'; // Note: This will safely close the program for an invalid index

  // Erasing a node
  cout << "Erasing 2 from the map." << "\n\n";
  newMap.erase(2);

  // cout << newMap.find(newMap.top(), 1)->next() << '\n';
  cout << "Copying map" << '\n';
  Map<int, string> map2(newMap);
  cout << "Map copied" << "\n\n";

  cout << "Inserting (40, \"Wat\") into the copied map." << "\n\n";
  map2.insert(40, "Wat");

  cout << "Size of map1: " << newMap.size() << "\n";
  cout << "Size of map2: " << map2.size() << "\n\n";

  newMap.insert(402, "cats 4");
  newMap.insert(3002, "i am a cow");
  cout << "iterator start" << '\n';
  for (auto itr = newMap.begin(); itr != newMap.end(); ++itr) {
    cout << itr->second << '\n';
  }
  cout << "iterator end" << "\n\n";
  
  cout << "Min node value before itr erase: " << newMap.begin()->second << '\n';
  newMap.erase(newMap.begin());
  cout << "Min node value after itr erase: " << newMap.begin()->second << '\n';

  cout << "Testing count on key 2: " << newMap.count(2) << '\n';
  cout << "Testing count on key 3002: " << newMap.count(3002) << '\n';
  return 0;
}
