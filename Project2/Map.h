#ifndef MAP_H
#define MAP_H

#include "MapNode.h"
#include <iostream>
#include <utility>

template <class K, class V>
class Map;

template <class K, class V>
class MapIterator {
public:
  friend class Map<K,V>;
  MapIterator<K, V>(MapNode<K,V> * node): current_node(node) {};
  std::pair<K,V> & operator *() { return current_node->element; }
  std::pair<K,V> * operator ->() { return &(current_node->element); }
  bool operator==(const MapIterator<K, V> & rhs) { return current_node == rhs.current_node; }
  bool operator!=(const MapIterator<K, V> & rhs) { return current_node != rhs.current_node; }

  void operator++() {
    current_node = current_node->next();
  }
private:
  MapNode<K,V> * current_node;
};

template <class K, class V>
class Map {
  public:
    Map <K,V>(): root(nullptr), size_(0) {};
    Map<K,V>(Map<K,V> & oldMap): size_(oldMap.size()) {
      if(oldMap.top() != nullptr) {
        root = new MapNode<K,V>(oldMap.top());
      }
    };
    ~Map<K,V>() { delete root; };
    Map<K,V> & operator=(Map<K,V> & otherMap) {
      this = new Map<K,V>(otherMap);
    }
    void insert(K key, V value);
    void erase(K key);
    int size() { return size_; };
    bool empty() { return root == nullptr; }
    void clear() { delete root; }
    V operator[](K key);
    int count(K key);
    MapNode<K,V> * top() { return root; }
    MapIterator<K,V> begin();
    MapIterator<K,V> begin(MapNode<K, V> * z);
    MapNode<K,V> * min(MapNode<K, V> * z);
    MapIterator<K,V> end();
    MapNode<K,V> * find(MapNode<K,V> * node, K key);
    void swap(K k1, K k2);
  private:
    MapNode<K,V> * root;
    void transplant(MapNode<K, V> * u, MapNode<K, V> * v);
    int size_;
};

/*
* insert(key, value) insert a node with specified key and value into the map
*/
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

/*
* erase(key): delete the node at map[key]
*/
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

/*
* transplant(u, v) put node v in the place of node u
*/
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

/*
* operator[](key) access the content of the map at key (map[key])
*/
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

/*
* count(key) count the number of elements with a key of key
*/
template <class K, class V>
int Map<K,V>::count(K key) {
  int total = 0;
  for(auto itr = begin(); itr != end(); ++itr) {
    if(itr->first == key) {
      total++;
    }
  }
  return total;
}

template <class K, class V>
MapIterator<K,V> Map<K,V>::begin(MapNode<K, V> * z) {
  MapNode<K, V> * x = z;
  while(x->getLeft() != nullptr)
    x = x->getLeft();
  return MapIterator<K, V>(x);
}

template <class K, class V>
MapNode<K,V> * Map<K,V>::min(MapNode<K, V> * z) {
  MapNode<K, V> * x = z;
  while(x->getLeft() != nullptr)
    x = x->getLeft();
  return x;
}

template <class K, class V>
MapIterator<K,V> Map<K,V>::end() {
  return MapIterator<K, V>(nullptr);
}

/*
* find(node, key): find a node starting at node with a key of key
*/
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

/*
* swap(k1, k2) swap the values between keys k1 and k2
*/
template <class K, class V>
void Map<K,V>::swap(K k1, K k2) {
  V temp = (find(root, k1))->getValue();
  find(root, k1)->setValue((find(root, k2))->getValue());
  find(root, k2)->setValue(temp);
}

template <class K, class V>
MapIterator<K, V> Map<K,V>::begin() {
  MapNode<K,V> * firstNode = root->min();
  return MapIterator<K,V>(firstNode);
}

#endif
