
#ifndef VECTOR_HPP
#define VECTOR_HPP

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

}

#endif