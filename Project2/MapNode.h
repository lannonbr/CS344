#ifndef MAPNODE_H
#define MAPNODE_H

template <class K, class V>
class MapNode {
public:
  MapNode(K key0, V value0): key(key0), value(value0) {};
  ~MapNode();
private:
  MapNode * parent, left, right;
  K key;
  V value;
};

#endif
