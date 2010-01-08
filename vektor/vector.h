class Vector {
    private:
        unsigned int size;
        unsigned int * vector;
    public:
        explicit Vector(unsigned int size);
        Vector(const Vector& copy);
        ~Vector();
        unsigned int & operator[](unsigned int index);
        unsigned int operator[](unsigned int index) const;
        void operator=(const Vector& copy);
};
