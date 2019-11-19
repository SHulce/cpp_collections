#ifndef Collectors_HPP
#define Collectors_HPP

#include <string>

namespace collectors {

template <typename T>
class vector {
    public:
         vector();
         T get(int index);
         void push_back(T value);
         int size();
         int capacity();
    private:
        T* storage;
        int DEFAULT_SIZE = 10;
        int current_capacity;
        int current_index;

        void grow_storage();
};

template <typename T>
class stack {
    public:
        stack();
        T pop();
        void push(T value);
        T peek();
        int count();
        bool empty();
    private:
        T* storage;
        int size;
        int capacity;
        int DEFAULT_CAPACITY = 10;
        void grow_storage();

};


}

#endif