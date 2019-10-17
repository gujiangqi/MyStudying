#pragma once

// 顺序存储模板类
template <typename T>
class SeqList
{
private:
    int capacity;
    int length;
    T *pArray; // 是一个数组

public:
    SeqList(int cap);

    ~SeqList();

    int getL();

    int getCapacity();

    int insert(T &node, int pos);

    int get(int pos, T &t); // 这样pos是输入，t是输出

    int del(int pos, T &t);
};