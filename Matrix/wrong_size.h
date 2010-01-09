#include <stdexcept>

class WrongSizeException : public std::logic_error {
    public:
        WrongSizeException() : std::logic_error("WrongSizeException") {}
};
