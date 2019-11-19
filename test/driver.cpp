#include <iostream>
#include <string>
#include "collectors.hpp"

int main() {
    collectors::vector<int> my_vector = collectors::vector<int>();
    int vector_size = 80000000;
    for (int i = 0; i < vector_size; i++) {
        my_vector.push_back(vector_size - i);
    }

    int value = my_vector.get(876543);
    value = 5;
    std::cout << "My Value: " << value << std::endl;
    std::cout << "\n\nmy_vector at same index: " << my_vector.get(876543) << std::endl;

    return 0;
}