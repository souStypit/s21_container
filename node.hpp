template <typename T>
struct Node {
    struct Node *next;
    T value;
    
    Node(T _value);
};

template <typename T>
Node<T>::Node(T _value) {
    next = nullptr;
    value = _value;
}
