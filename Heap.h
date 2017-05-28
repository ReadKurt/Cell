//
// Created by WJ on 2017/5/28.
//

#ifndef CELL_HEAP_H
#define CELL_HEAP_H

template <typename T>
class Heap{
public:
    virtual void insert(const T &) = 0;
    virtual void top() = 0;
    virtual bool isEmpty() = 0;
};
#endif //CELL_HEAP_H
