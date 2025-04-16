// Copyright 2025 NNTU-CS

#ifndef SRC_TSTACK_H_  // <- Исправлено!
#define SRC_TSTACK_H_  // <- Исправлено!

#include <array>
#include <stdexcept>
#include <string>

template<typename T, int size>
class TStack {
 public:
    TStack() : elements(), top(-1) {}

    bool isEmpty() const noexcept {
        return top == -1;
    }

    bool isFull() const noexcept {
        return top == size - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        elements[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return elements[top--];
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty");
        }
        return elements[top];
    }

    void clear() noexcept {
        top = -1;
    }

 private:
    std::array<T, size> elements;
    int top;
};

#endif  // SRC_TSTACK_H_  // <- Исправлено!
