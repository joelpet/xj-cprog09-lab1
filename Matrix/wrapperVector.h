#include "vector.h"

class wrapperVector {
    private:
        Vector<int> * vector;
        bool isSizeSet;
    public:
        explicit wrapperVector(int size) : isSizeSet(true) {
            vector = new Vector<int>(size);
        }

        explicit wrapperVector() : isSizeSet(false) {}

        void setSize(int size) {
            if (isSizeSet)
                return;
            isSizeSet = true;

            vector = new Vector<int>(size);

        }

        int operator[](unsigned int index) const {
            return (*vector)[index];
        }

        int & operator[](unsigned int index) {
            return (*vector)[index];
        }
};
