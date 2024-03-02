#include "node.hpp"

// Container LinkedList
template <typename T, class Allocator = Node<T>>
class LinkedList {
   private:
    Allocator *head;

   public:
    LinkedList();

    void Insert(T _value);
    void RemoveAt(int _index);
    void Representer();
    bool IsEmpty();
};

template <typename T, class Allocator>
LinkedList<T, Allocator>::LinkedList() : head(nullptr) {}

template <typename T, class Allocator>
void LinkedList<T, Allocator>::Insert(T _value) {
    Allocator *newAlloc = new Allocator(_value);

    if (head == nullptr) {
        head = newAlloc;
    } else {
        Allocator *curAlloc = head;
        while (curAlloc->GetNextPtr() != nullptr) {
            curAlloc = curAlloc->GetNextPtr();
        }
        curAlloc->SetNextPtr(newAlloc);
    }
}

template <typename T, class Allocator>
void LinkedList<T, Allocator>::RemoveAt(int _index) {}

template <typename T, class Allocator>
void LinkedList<T, Allocator>::Representer() {
    Allocator *curAlloc = head;
    std::cout << "Container [" << std::endl;
    while (curAlloc != nullptr) {
        std::cout << "\t" << curAlloc->Representer() << std::endl;
        curAlloc = curAlloc->GetNextPtr();
    }
    std::cout << "]" << std::endl;
}

template <typename T, class Allocator>
bool LinkedList<T, Allocator>::IsEmpty() { return head == nullptr; }