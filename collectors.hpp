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
    private:
        T* storage;
        int DEFAULT_SIZE = 10;
        int current_size;
        int current_index;

        void grow_storage();
};


}

#endif