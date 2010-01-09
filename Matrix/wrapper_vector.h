#include "vector.h"

class WrapperVector {
    private:
        Vector<int> * vector;
        bool is_size_set;
    public:
        explicit WrapperVector(int size) : is_size_set(true) {
            vector = new Vector<int>(size);
        }

        explicit WrapperVector() : is_size_set(false) {}

        void set_size(int size) {
            if (is_size_set)
                return;

            is_size_set = true;

            vector = new Vector<int>(size);
        }

        int operator[](unsigned int index) const {
            return (*vector)[index];
        }

        int & operator[](unsigned int index) {
            return (*vector)[index];
        }
};
