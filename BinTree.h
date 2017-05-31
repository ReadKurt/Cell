//
// Created by WJ on 2017/5/27.
//

#ifndef CELL_BTREE_H
#define CELL_BTREE_H

template <typename T>
class BinTree{
public:
    virtual void insert(const T &) = 0;
    virtual void remove(const T &) = 0;
};



#endif //CELL_BTREE_H
