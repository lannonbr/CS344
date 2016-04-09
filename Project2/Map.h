#ifndef MAP_H
#define MAP_H
template <class K, class V>
class Map {
  public:
    void insert(K key, V value);
    void erase(K key);
    int size();
    bool empty();
    V operator[](K key);
  private:
    MapNode <K,V> root;

};
#endif
