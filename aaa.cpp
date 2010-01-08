#include <iostream>
class A {
public:
    A()
        {std::cout << "_______________A()_____________" << std::endl; }
    A(const A & ref)
        {std::cout << "_______________A(const A & ref)" << std::endl; }
    ~A()
        {std::cout << "_______________~A()____________" << std::endl; }
    A(char * s)
        {std::cout << "_______________A(char * s)_____" << s << std::endl;}
    A & operator=(const A & s)
        {std::cout << "____A & operator=(const A & s)_" << std::endl;
         return *this;}
};
void no_ref(A a) {}
void with_ref(const A &a) {}

int main()
{
    std::cout << "a a(my name is a)" << std::endl;
    A a("my name is a");
    std::cout << "b = a" << std::endl;
    A b = a;         // vad är skillnaden
    std::cout << "c(a)" << std::endl;
    A c(a);          // mellan dessa
    std::cout << "A d" << std::endl;
    A d;             // tre tekniker?
    std::cout << "d = a" << std::endl;
    d = a;
    A *aa = new A[5];
    delete aa;       // Vad kommer att hända?
    no_ref(a);       // Bildas temporära objekt?
    with_ref(a);     // Bildas temporära objekt?
    return 0;
}
