#ifndef MAPNODE_H
#define MAPNODE_H

template <class K, class V>
class MapNode {
public:
  MapNode<K,V>(K key0, V value0): key(key0), value(value0) {};
  ~MapNode();
  K getKey() { return key; }
  MapNode * getLeft() { return left; }
  MapNode * getRight() { return right; }
  MapNode * getParent() { return parent; }
  V getValue() { return value; }

  void setLeft(MapNode * z) { left = z; }
  void setRight(MapNode * z) { right = z; }
  void setParent(MapNode * z) { parent = z; }
private:
  MapNode<K,V> * parent, * left, * right;
  K key;
  V value;
};

#endif