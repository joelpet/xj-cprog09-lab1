#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

// Contains changes not in the original vectorTemplate

template <class T> 
class Vector {
    private:
        unsigned int capacity;
        unsigned int vectorSize;
        static const unsigned int capacityIncreaseFactor = 2;
        T * vector;
    public:
        explicit Vector() : capacity(1), vectorSize(0) {
            vector = new T[capacity];
        }

        explicit Vector(unsigned int space)  : capacity(space), vectorSize(space) {
            vector = new T[capacity];
            for (unsigned int i = 0; i < capacity; i++) {
//                vector[i] = T();
            }
        }

        explicit Vector(unsigned int space, T defaultValue) : capacity(space), vectorSize(space) {
            vector = new T[capacity];
            for (int i = 0; i < capacity; i++) {
                vector[i] = defaultValue;
            }
        }

        Vector(const Vector& copy) {
            this->vectorSize = copy.vectorSize;
            this->capacity = copy.capacity;
            vector = new T[capacity];

            for (int i = 0; i < vectorSize; i++) {
                vector[i] = copy.vector[i];
            }
        }

        ~Vector() {
            delete[] vector;
        }

        T & operator[](unsigned int index) {
            if (index >= vectorSize) { 
                throw std::out_of_range("index out of range");
            }
            return vector[index];
        }

        T operator[](unsigned int index) const {
            if (index >= vectorSize) {
                throw std::out_of_range("index out of range");
            } 
            return vector[index];
        }

        void operator=(const Vector& copy) {
            if (&(copy.vector) == &(this->vector)) {
                return;
            }

            delete[] this->vector;

            this->capacity = copy.capacity;
            this->vectorSize = copy.vectorSize;
            vector = new T[capacity];

            for (unsigned int i = 0; i < vectorSize; i++) {
                vector[i] = copy.vector[i];
            }
        }

        int size() const {
            return vectorSize;
        }

        void push_back(T object) {
            if (vectorSize >= capacity) 
                increaseCapacity();
            vector[vectorSize] = object;
            vectorSize++;
        }

        /**
         * Inserts an object into the specified position
         * and shifts all objects with a higher index to 
         * the right
         */
        void insert(unsigned int i, T object) {
            if (vectorSize == i) {
                push_back(object);
                return;
            }
            else if (i > vectorSize) {
                throw std::out_of_range("index out of range");
                return;
            } else {
                if (vectorSize+1 > capacity) 
                    increaseCapacity();
                for (int n = vectorSize; n > i; n--) {
                    vector[n] = vector[n-1];
                }
                vector[i] = object;
                vectorSize++;
            }
        }

        /**
         * Removes the pointer on position i
         *
         * The addressed object itself will not be deleted
         */
        void erase(unsigned int i) {
            if (i >= vectorSize) {
                throw std::out_of_range("index out of range");
            }
            else {
                for (; i < vectorSize-1; i++) {
                    vector[i] = vector[i+1];
                }
                vectorSize--;
            }
        }

        /**
         * Clears the vector by setting the vectorSize to 0
         */
        void clear() {
            vectorSize = 0;
        }

        void sort(bool asc = true) {
            if (vectorSize <= 1) {
                return;
            }
            if (asc)
                quickSort(0, vectorSize-1);
            else
                backSort(0, vectorSize-1);
        }

        void quickSort(int left, int right) {
            int i = left;
            int j = right;
            // TODO is this really correct???!!!!1111oneoneoneone!!c:w
            T tmp;
            T pivot = vector[(left+right)/2];

            while (i <= j) {
                while (vector[i] < pivot) {
                    i++;
                }
                while (pivot < vector[j]) {
                    j--;
                }
                if (i <= j) {
                    tmp = vector[i];
                    vector[i] = vector[j];
                    vector[j] = tmp;
                    i++;
                    j--;
                }
            }
            if (left < j) 
                quickSort(left, j);
            if (i < right)
                quickSort(i, right);
        }

        void backSort(int left, int right) {
            quickSort(left, right);

            T tmp;

            while (left < right) {
                std::cerr << "swaping vector[" << left << "] and vector[" << right << "]" << std::endl;
                tmp = vector[left];
                vector[left] = vector[right];
                vector[right] = tmp;
                left++;
                right--;
            }
        }
        // void backSort(int left, int right) {
            // int i = left;
            // int j = right;
            // T tmp;
            // T pivot = vector[(left+right)/2];
            // // std::cerr << "left:\t" << left << "\tright:\t" << right << std::endl;
            // // std::cerr << (left+right)/2 << "pivot:\t" << pivot << std::endl;
// 
            // while (i <= j) {
                // while (pivot < vector[i]) {
                    // i++;
                // }
                // while (vector[j] < pivot) {
                    // j--;
                // }
                // if (i <= j) {
                    // tmp = vector[i];
                    // vector[i] = vector[j];
                    // vector[j] = tmp;
                    // i++;
                    // j--;
                // }
            // }
            // if (left < j) 
                // quickSort(left, j);
            // if (i < right)
                // quickSort(i, right);
        // }

        /**
         * Increases the capacity of our vector
         */
        void increaseCapacity() {
            if (capacity == 0) {
                capacity = 2;
                vector = new T[capacity];
                return;
            }
            T * oldVector = vector;
            vector = new T[capacity*capacityIncreaseFactor];

            for (int i = 0; i < capacity; i++) {
                vector[i] = oldVector[i];
            }

            delete[] oldVector;

            capacity *= capacityIncreaseFactor;
        }

        bool is_empty() const {
            return vectorSize == 0;
        }

        void printVector() const {
            std::cerr << "size:\t" << vectorSize << std::endl;
            for (int i = 0; i < vectorSize; i++) {
                std::cerr << "[" << i << "] = " << vector[i] << std::endl;
            }
            std::cerr << std::endl;
        }


};

#endif // header guard
