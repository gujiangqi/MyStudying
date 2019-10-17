#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int cap)
{
    pArray = new T[cap];
    this->length = 0;
    this->capacity = cap;
};

template <typename T>
SeqList<T>::~SeqList()
{
    delete[] pArray;
    pArray = NULL;
    length = 0;
    capacity = 0;
};

template <typename T>
int SeqList<T>::getL()
{
    return this->length;
};

template <typename T>
int SeqList<T>::getCapacity()
{
    return this->capacity;
}

template <typename T>
int SeqList<T>::insert(T &t, int pos)
{
    int i = 0, ret = 0;
    if (&t == NULL || pos < 0)
    {
        return -1;
    }

    for (i = this->length; i > pos; i--)
    {
        pArray[i] = pArray[i - 1];
    }

    pArray[i] = t;
    this->length++;

    return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T &t) // 这样pos是输入，t是输出
{
    int i = 0;
    if (&t == NULL || pos < 0)
    {
        return -1;
    }
    t = pArray[pos];
    return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t)
{
    t = pArray[pos];
    for (int i = pos + 1; i < this->length; i++)
    {
        this->pArray[i - 1] = this->pArray[i];
    }
    length--;
    return 0;
}
