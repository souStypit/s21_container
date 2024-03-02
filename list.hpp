#include "node.hpp"

template <typename T>
class List {
private:
    Node<T> *head;
    
public:
    List();
    
    void Insert(T _pair);
    void Erase(T _pair);
    int IsKey(T _pair);
    void Print();
    bool IsEmpty();
};

template <typename T>
List<T>::List() { head = nullptr; }

template <typename T>
void List<T>::Insert(T _pair) {
    Node<T> *newNode = new Node<T>(_pair);
    
    if (head == nullptr) {
        head = newNode;
        head->next = nullptr;
        return;
    }
    
    Node<T> *curNode = head;
    while (curNode->next != nullptr) {
        curNode = curNode->next;
    }
    curNode->next = newNode;
}

template <typename T>
void List<T>::Erase(T _pair) {
    if (IsEmpty()) return;
    
    if (head->value.first == _pair.first) {
        Node<T> *tmp = head->next;
        delete head;
        head = tmp;
        return;
    }
    
    Node<T> *curNode = head->next, *prt = head;
    while (curNode != nullptr) {
        if (curNode->value.first == _pair.first) {
            prt->next = curNode->next;
            delete curNode;
            return;
        }
        prt = curNode;
        curNode = curNode->next;
    }
}

template <typename T>
int List<T>::IsKey(T _pair) {
    Node<T> *curNode = head;
    while (curNode != nullptr) {
        if (curNode->value.first == _pair.first) 
            return true;
        curNode = curNode->next;
    }
    return false;
}

template <typename T>
void List<T>::Print() {
    Node<T> *curNode = head;
    std::cout << "Container [" << std::endl;
    while (curNode != nullptr) {
        std::cout << "\tkey: "<< curNode->value.first \
            << "\tvalue: " << curNode->value.second << std::endl;
        curNode = curNode->next;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
bool List<T>::IsEmpty() { return head == nullptr; }
