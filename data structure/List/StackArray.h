#include <iostream>
#include <vector>

template <typename T>
class StackArray {
public:
    StackArray(int maxSize) : max_size(maxSize), top_of_stack(-1) {
        the_array.resize(maxSize);
    }

    bool isEmpty() const {
        return top_of_stack == -1;
    }

    bool isFull() const {
        return top_of_stack == max_size - 1;
    }

    void push(const T& value) {
        if (!isFull()) {
            the_array[++top_of_stack] = value;
        } else {
            std::cerr << "Stack is full. Cannot push more elements." << std::endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --top_of_stack;
        } else {
            std::cerr << "Stack is empty. Cannot pop an element." << std::endl;
        }
    }

    T peek() const {
        if (!isEmpty()) {
            return the_array[top_of_stack];
        } else {
            std::cerr << "Stack is empty." << std::endl;
            throw std::runtime_error("Stack is empty.");
        }
    }

    size_t size() const {
        return top_of_stack + 1;
    }

private:
    std::vector<T> the_array;
    int max_size;
    int top_of_stack;
};


