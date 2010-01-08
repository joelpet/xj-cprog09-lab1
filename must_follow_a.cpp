#include <iostream>

/**
   must_follow_a will return the number of times a is immediately
   followed by b in the interval defined by start and length
*/
int must_follow_a(char * start, int length, char a, char b) {
    int nr = 0;
    for (int i = 0; i < length; i++, ++start) {
        if (*start == a && *(start + 1) == b) // maintainers note: DANGER!
            nr += 1;
    }
    return nr;
}

