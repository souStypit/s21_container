#pragma once

template <typename T>
class NodeAbstraction {
   public:
    virtual const std::string Representer() const = 0;
};

// NOT an Allocator
template <typename T>
class Node : public NodeAbstraction<T> {
   private:
    class Node *next;
    T value;

   public:
    Node(T _value, class Node *_ptr = nullptr);

    const T &GetValue() const;
    void SetValue(T _value);

    class Node *GetNextPtr() const;
    void SetNextPtr(class Node *_ptr);

    const std::string Representer() const override;
};

template <typename T>
Node<T>::Node(T _value, class Node *_ptr) : value(_value), next(_ptr) {}

template <typename T>
const T &Node<T>::GetValue() const {
    return value;
}
template <typename T>
void Node<T>::SetValue(T _value) {
    value = _value;
}

template <typename T>
class Node<T> *Node<T>::GetNextPtr() const {
    return next;
} template <typename T>
void Node<T>::SetNextPtr(class Node *_ptr) {
    next = _ptr;
}

template <typename T>
const std::string Node<T>::Representer() const {
    char buf[20];
    sprintf(buf, "%p", next);
    return "Node [ Value: " + std::to_string(value) +
           " NextNode: " + std::string(buf) + " ]";
}
