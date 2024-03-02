#include "stack.hpp"

int main() {
    Stack<double> st = Stack<double>(5);

    try {
        st.Push(1);
        st.Print();
    } catch (const std::out_of_range& error) {
        std::cout << "Out of range: " << error.what() << std::endl;
    }

    return 0;
}
