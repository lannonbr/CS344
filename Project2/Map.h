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
    void erase(K key);
    int size() { return size_; };
    bool empty() { return root == nullptr; }
    void clear() { delete root; }
    V operator[](K key);
    MapNode<K,V> * top() { return root; }
    MapNode<K,V> * min(MapNode<K, V> * z);
    MapNode<K,V> * max(MapNode<K, V> * z);
  private:
    MapNode<K,V> * root;
    MapNode<K,V> * find(MapNode<K,V> * node, K key);
    void transplant(MapNode<K, V> * u, MapNode<K, V> * v);
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
    size_ += 1;
    delete x;
  }
}

template <class K, class V>
void Map<K,V>::erase(K key) {
  MapNode<K, V> * z = find(root, key);
  if (z == nullptr) {
    std::cout << "Element not found.\n";
    return;
  }

  if (z->getLeft() == nullptr) {
    transplant(z, z->getRight());
  } else if (z->getRight() == nullptr) {
    transplant(z, z->getLeft());
  } else {
    MapNode<K, V> * y = min(z->getRight());
    if (y != z->getRight()) {
      transplant(y, y->getRight());
      y->setRight(z->getRight());
      z->getRight()->setParent(y);
    }
    transplant(z, y);
    y->setLeft(z->getLeft());
    y->getLeft()->setParent(y);
  }
  z->setParent(nullptr);
  z->setLeft(nullptr);
  z->setRight(nullptr);
  delete z;
}

template <class K, class V>
void Map<K, V>::transplant(MapNode<K, V> * u, MapNode<K, V> * v) {
  if (root == u) {
    root = v;
    v->setParent(nullptr);
  } else {
    MapNode<K, V> * q = u->getParent();
    if (q->getLeft() == u) {
      q->setLeft(v);
    } else {
      q->setRight(v);
    }
    v->setParent(q);
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
MapNode<K,V> * Map<K,V>::min(MapNode<K, V> * z) {
  MapNode<K, V> * x = z;
  while(x->getLeft() != nullptr)
    x = x->getLeft();
  return x;
}

template <class K, class V>
MapNode<K,V> * Map<K,V>::max(MapNode<K, V> * z) {
  MapNode<K, V> * x = z;
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
