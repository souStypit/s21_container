#include <iostream>

#include "linkedList.hpp"
#include "map.hpp"

int main() {
    LinkedList<int> n = LinkedList<int>();

    n.Insert(5);
    n.Insert(4);
    n.Insert(4);
    if (!n.IsEmpty()) n.Representer();

    // Node<int> nd = Node<int>(5);

    return 0;
}