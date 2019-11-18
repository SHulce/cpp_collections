#include "collectors.hpp"
#include <string>

namespace collectors {
    template <typename T>
    vector<T>::vector() {
        storage = new T[DEFAULT_SIZE];
        current_size = DEFAULT_SIZE;
        current_index = 0;
    }

    template <typename T>
    T vector<T>::get(int index) {
        if (index >= current_size) {
            throw 0;
        }

        return storage[index];
    }

    template <typename T>
    int vector<T>::size() {
        return current_size;
    }

    template <typename T>
    void vector<T>::push_back(T item) {
        if (current_index > current_size / 2) {
            grow_storage();
        }

        storage[current_index] = item;
        current_index++;
    }

    template <typename T>
    void vector<T>::grow_storage() {
        T* temp = new T[current_size * 2];
        for (int i = 0; i < current_index; i++) {
            temp[i] = storage[i];
        }
        current_size *= 2;
        delete[] storage;
        storage = temp;
    }
}

template class collectors::vector<int>;
template class collectors::vector<std::string>;
