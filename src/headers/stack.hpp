#ifndef STACK_HPP
#define STACK_HPP

namespace collectors {

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