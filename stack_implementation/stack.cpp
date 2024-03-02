#include "stack.hpp"

template<typename T>
Stack<T>::Stack(int totalSize) : totalSize(totalSize), size(0) {
    this->value = new T[totalSize];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] this->value;
}

template<typename T>
void Stack<T>::Push(T value) {
    if (this->Full()) throw std::out_of_range("Stack Overflow");
    this->value[this->size++] = value;
}

template <typename T>
T Stack<T>::Pop() {
    if (this->Empty()) throw std::out_of_range("Stack Empty");
    return this->value[--this->size];
}

template <typename T>
T Stack<T>::Peek() {
    return this->value[this->size - 1];
}

template<typename T>
void Stack<T>::Print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->value[i] << " ";
    }
    std::cout << endl;
}


template<typename T>
bool Stack<T>::Empty() {
    return this->size <= 0;
}

template<typename T>
bool Stack<T>::Full() {
    return this->size >= this->totalSize;
}
