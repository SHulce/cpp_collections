#include "../headers/stack.hpp"
#include <string>

namespace collectors {
    template <typename T>
    stack<T>::stack() {
        storage = new T[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
        size = 0;
    }

    template <typename T>
    void stack<T>::push(T value) {
        if (size > capacity / 2) {
            grow_storage();
        }
        storage[size] = value;
        size++;
    }

    template <typename T>
    T stack<T>::pop() {
        size--;
        return storage[size];
    }

    template <typename T>
    T stack<T>::peek() {
        return storage[size - 1];
    }

    template <typename T>
    void stack<T>::grow_storage() {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = storage[i];
        }
        capacity *= 2;
        delete[] storage;
        storage = temp;
    }

    template <typename T>
    int stack<T>::count() {
        return size;
    }

    template <typename T>
    bool stack<T>::empty() {
        return size == 0;
    }
}


template class collectors::stack<int>;
template class collectors::stack<std::string>;
template class collectors::stack<double>;
template class collectors::stack<float>;