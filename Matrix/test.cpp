#include "matrix.h"
#include <assert.h>             // assert(b) ger felmeddelande om b falsk

int main() {
    int x = 10;
    int y = 11;
    Matrix a(x,y);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            a[i][j] = i*1000+j;
        }
    }
    a[7][2] = -4711;
    assert(a[7][2] == -4711);

    std::cout << "----" << std::endl;
    std::cout << a << std::endl;
}
