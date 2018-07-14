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
        static void insertSortExecute(int *array,int length);
        static void mergeSort();
        static void mergeSortExecute(int *array,int p,int r);
        static void merge(int *array,int p,int q,int r);
    protected:

    private:

};
GAKKI_REGISTER_ALGORITHM(2,"插入排序",Chapter2::insertSort);
GAKKI_REGISTER_ALGORITHM(3,"归并排序",Chapter2::mergeSort);
#endif // CHAPTER2_H
