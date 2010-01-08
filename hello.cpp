#include<iostream>
#include<cstdlib>

int main(int argc, char *argv[]) {
    std::cout << "Hello";
    switch (argc) {
        case 1: std::cout << " word"; break;
        case 2: std::cout << " " << argv[1]; break;
        default:
                if (argc >= 3) {
                    int numberOfPrints = atoi(argv[1]);
                    while (numberOfPrints-- > 0) {
                        std::cout << " " << argv[2];
                    }
                }
    }
    std::cout << "!" << std::endl;
}
