#ifndef MAPNODE_H
#define MAPNODE_H

template <class K, class V>
class MapNode {
public:

  MapNode<K,V>(K key, V value): element(std::pair<K,V>(key,value)) {};
  // MapNode<K,V>(const MapNode<K,V> & oldNode);
  MapNode<K,V>(MapNode<K,V> * oldNode) {
    // if(oldNode == nullptr) return;

    setKey(oldNode->getKey());
    setValue(oldNode->getValue());
    if(oldNode->getParent() != nullptr) {
        parent = oldNode->getParent();
    }

    if(oldNode->getLeft() != nullptr) {
      left = new MapNode<K,V>(oldNode->getLeft());
    }

    if(oldNode->getRight() != nullptr) {
      right = new MapNode<K,V>(oldNode->getRight());
    }
  }
  ~MapNode();

  MapNode * getLeft() { return left; }
  MapNode * getRight() { return right; }
  MapNode * getParent() { return parent; }

  // MapNode * next();

  K getKey() { return element.first; }
  V getValue() { return element.second; }

  void setKey(K newKey) { element.first = newKey; }
  void setValue(V newValue) { element.second = newValue; }

  void setLeft(MapNode * z) { left = z; }
  void setRight(MapNode * z) { right = z; }
  void setParent(MapNode * z) { parent = z; }

  // MapNode * min(MapNode * z);
private:
  MapNode<K,V> * parent, * left, * right;
  std::pair<K,V> element;

  // K key;
  // V value;
};

// template <class K, class V>
// MapNode<K,V>::

template <class K, class V>
MapNode<K,V>::~MapNode() {
  delete left; // Recursively get rid of any node to the left
  delete right; // Recursively get rid of any node to the right
}

// template <class K, class V>
// MapNode<K,V> * MapNode<K,V>::next() {
//   if(getRight() != nullptr) {
//     return min(getRight());
//   } else {
//     MapNode<K,V> * y = getParent();
//     MapNode<K,V> * x = this;
//     while(y != nullptr && y.getRight() == x) {
//       x = y;
//       y = y.getParent();
//     }
//     return y;
//   }
// }
//
// template <class K, class V>
// MapNode<K,V> * MapNode<K,V>::min(MapNode<K, V> * z) {
//   MapNode<K, V> * x = z;
//   while(x->getLeft() != nullptr)
//     x = x->getLeft();
//   return x;
// }


#endif
