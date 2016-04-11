#ifndef MAP_H
#define MAP_H

#include "MapNode.h"
#include <iostream>

template <class K, class V>
class Map {
  public:
    Map <K,V>(): root(nullptr), size_(0) {};
    ~Map<K,V>() { delete root; }
    void insert(K key, V value);
    // void erase(K key);
    int size() { return size_; };
    bool empty() { return root == nullptr; }
    V operator[](K key);
    MapNode<K,V> * min();
    MapNode<K,V> * max();
  private:
    MapNode<K,V> * root;
    MapNode<K,V> * find(MapNode<K,V> * node, K key);
    int size_;
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
    size += 1;
    delete x;
  }
}

template <class K, class V>
V Map<K,V>::operator[](K key) {
  MapNode<K,V> * node = root;
  node = find(node, key);
  if(node == nullptr) {
    std::cerr << "ERROR: Not a valid key: " << key << "\nExiting\n";
    delete node;
    delete root;
    exit(1);
  }
  return node->getValue();
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

template <class K, class V>
MapNode<K,V> * Map<K,V>::find(MapNode<K,V> * node, K key) {
  while(node != nullptr) {
    if(node->getKey() == key) {
      return node;
    } else if(node->getKey() < key) {
      node = node->getRight();
    } else if(node->getKey() > key) {
      node = node->getLeft();
    }
  }
  return nullptr;
}

#endif
