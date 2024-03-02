#include <iostream>
using namespace std;

template<typename T>
class Stack {
  private:
    int size;
    int totalSize;
    T *value;

  public:
    Stack(int totalSize);
    ~Stack();

    void Push(T value);
    T Pop();
    T Peek();
    bool Empty();
    bool Full();
    void Print();
};
