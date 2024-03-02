#include "node.hpp"

// Container Map (implements as Red-black Tree)
template <typename Key, typename T, class Allocator = Node<T>>
class Map {
   private:
    Allocator *Alloc;

   public:
    Map() : Alloc(nullptr) {}
};