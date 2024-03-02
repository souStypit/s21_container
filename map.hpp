#include "list.hpp"

template <typename K, typename M>
class Map {
private:
    typedef K key_type;
    typedef M map_type;
    typedef std::pair<key_type, map_type> value_type;
    typedef List<value_type> container_type;
    
    container_type container;
    
public:
    Map();
    ~Map();
    
    void Insert(const value_type &v);
    void Erase(key_type _key);
    bool IsKey(const value_type &v);
    bool IsKey(key_type _key);
    bool IsEmpty();
    void Print() ;

};

template <typename K, typename M>
Map<K,M>::Map() { container = container_type(); }

template <typename K, typename M>
Map<K,M>::~Map() { };

template <typename K, typename M>
void Map<K,M>::Insert(const value_type &v) {
    if (!container.IsKey(v)) container.Insert(v);
}

template <typename K, typename M>
void Map<K,M>::Erase(key_type _key) { container.Erase({_key, 0}); }

template <typename K, typename M>
bool Map<K,M>::IsKey(const value_type &v) { return container.IsKey({v.first, 0}); }

template <typename K, typename M>
bool Map<K,M>::IsKey(key_type _key) { return container.IsKey({_key, 0}); }

template <typename K, typename M>
bool Map<K,M>::IsEmpty() { return container.IsEmpty(); }

template <typename K, typename M>
void Map<K,M>::Print() { container.Print(); }
