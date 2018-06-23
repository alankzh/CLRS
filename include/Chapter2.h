#ifndef CHAPTER2_H
#define CHAPTER2_H

#include <iostream>
#include "gakki_algorithm.h"

class Chapter2
{
    public:
        Chapter2();
        virtual ~Chapter2();
        static void insertSort();
    protected:

    private:
};
GAKKI_REGISTER_ALGORITHM(2,"≤Â»Î≈≈–Ú",Chapter2::insertSort);

#endif // CHAPTER2_H
