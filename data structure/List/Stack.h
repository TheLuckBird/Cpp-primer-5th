#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    T peek() const {
        if (!isEmpty()) {
            return top->data;
        } else {
            // Handle the case when the stack is empty, e.g., throw an exception or return a default value.
            throw std::runtime_error("Stack is empty.");
        }
    }

private:
    Node<T>* top;
};


