#ifndef MAP_H
#define MAP_H

#include "MapNode.h"

template <class K, class V>
class Map {
  public:
    Map <K,V>(): root(nullptr) {};
    void insert(K key, V value);
    // void erase(K key);
    // int size();
    // bool empty();
    // V operator[](K key);
    MapNode<K,V> * min();
    MapNode<K,V> * max();
  private:
    MapNode<K,V> * root;
};

template <class K, class V>
void Map<K,V>::insert(K key, V value) {
  MapNode<K,V> * z = new MapNode<K,V>(key, value);
  if(root == nullptr)
    root = z;
  else {
    MapNode<K,V> * y = nullptr;
    MapNode<K,V> * x = root;
    while(x != nullptr) {
      y = x;
      if(z->getKey() < x->getKey())
        x = x->getLeft();
      else
        x = x->getRight();
    }
    if(z->getKey() < y->getKey())
      y->setLeft(z);
    else
      y->setRight(z);
    z->setParent(y);
  }
}

template <class K, class V>
MapNode<K,V> * Map<K,V>::min() {
  MapNode<K,V> * x = root;
  while(x->getLeft() != nullptr)
    x = x->getLeft();
  return x;
}

template <class K, class V>
MapNode<K,V> * Map<K,V>::max() {
  MapNode<K,V> * x = root;
  while(x->getRight() != nullptr)
    x = x->getRight();
  return x;
}

#endif
