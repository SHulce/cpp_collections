#include "../headers/vector.hpp"
#include <string>

namespace collectors {

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
} // namespace

template class collectors::vector<int>;
template class collectors::vector<std::string>;
template class collectors::vector<double>;
template class collectors::vector<float>;
