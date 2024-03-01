#include <iostream>
using namespace std;

template <typename T>
struct Node {
    struct Node *next;
    T value;
    
    Node(T _value) {
        next = nullptr;
        value = _value;
    }
};

template <typename T>
class List {
private:
    Node<T> *head;
    
public:
    List() { head = nullptr; }
    
    void Insert(T _pair) {
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
    
    void Erase(T _pair) {
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
    
    int IsKey(T _pair) {
        Node<T> *curNode = head;
        while (curNode != nullptr) {
            if (curNode->value.first == _pair.first) 
                return true;
            curNode = curNode->next;
        }
        return false;
    }
    
    void Print() {
        Node<T> *curNode = head;
        std::cout << "Container [" << endl;
        while (curNode != nullptr) {
            std::cout << "\tkey: "<< curNode->value.first \
                << "\tvalue: " << curNode->value.second << endl;
            curNode = curNode->next;
        }
        std::cout << "]" << endl;
    }
    
    bool IsEmpty() { return head == nullptr; }
};

template <typename K, typename M>
class Map {
private:
    typedef K key_type;
    typedef M map_type;
    typedef pair<key_type, map_type> value_type;
    typedef List<value_type> container_type;
    
    container_type container;
    
public:
    Map() { container = container_type(); }
    ~Map() { };
    
    void Insert(const value_type &v) {
        if (!container.IsKey(v)) container.Insert(v);
    }
    
    void Erase(key_type _key) { container.Erase({_key, 0}); }
    
    bool IsKey(const value_type &v) { return container.IsKey({v.first, 0}); }
    
    bool IsKey(key_type _key) { return container.IsKey({_key, 0}); }
    
    bool IsEmpty() { return container.IsEmpty(); }
    
    void Print() { container.Print(); }

};

int main() {
    Map<int, double> mp = Map<int, double>();
    
    mp.Print();
    
    return 0;
}
