#include "collectors.hpp"
#include <string>

namespace collectors {
    //Vector Impl
    template <typename T>
    vector<T>::vector() {
        storage = new T[DEFAULT_SIZE];
        current_capacity = DEFAULT_SIZE;
        current_index = 0;
    }

    template <typename T>
    T vector<T>::get(int index) {
        if (index >= current_capacity) {
            throw 0;
        }

        return storage[index];
    }

    template <typename T>
    int vector<T>::size() {
        return current_index;
    }

    template <typename T>
    int vector<T>::capacity() {
        return current_capacity;
    }

    template <typename T>
    void vector<T>::push_back(T item) {
        if (current_index > current_capacity / 2) {
            grow_storage();
        }

        storage[current_index] = item;
        current_index++;
    }

    template <typename T>
    void vector<T>::grow_storage() {
        T* temp = new T[current_capacity * 2];
        for (int i = 0; i < current_index; i++) {
            temp[i] = storage[i];
        }
        current_capacity *= 2;
        delete[] storage;
        storage = temp;
    }
    //End Vector Impl
    //Stack Impl
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

    //End Stack Impl
}

template class collectors::vector<int>;
template class collectors::vector<std::string>;
template class collectors::vector<double>;
template class collectors::vector<float>;

template class collectors::stack<int>;
template class collectors::stack<std::string>;
template class collectors::stack<double>;
template class collectors::stack<float>;
