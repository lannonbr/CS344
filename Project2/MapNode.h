#ifndef MAPNODE_H
#define MAPNODE_H

template <class K, class V>
class MapNode {
public:

  MapNode<K,V>(K key, V value): element(std::pair<K,V>(key,value)) {};
  ~MapNode();

  MapNode * getLeft() { return left; }
  MapNode * getRight() { return right; }
  MapNode * getParent() { return parent; }

  K getKey() { return element.first; }
  V getValue() { return element.second; }

  void setValue(V newValue) { element.second = newValue; }

  void setLeft(MapNode * z) { left = z; }
  void setRight(MapNode * z) { right = z; }
  void setParent(MapNode * z) { parent = z; }
private:
  MapNode<K,V> * parent, * left, * right;
  std::pair<K,V> element;

  // K key;
  // V value;
};

template <class K, class V>
MapNode<K,V>::~MapNode() {
  delete left; // Recursively get rid of any node to the left
  delete right; // Recursively get rid of any node to the right
}

#endif
