//
// Created by WJ on 2017/5/27.
//

#ifndef CELL_BTREE_H
#define CELL_BTREE_H

#include <iostream>

template <typename T>
class BTree{
public:
    virtual void insert(const T &) = 0;
    virtual void remove(const T &) = 0;
    virtual void destory() = 0;
    virtual const T & find(const T &) = 0;
};

template <typename T, typename Comp=std::less<T>>
class BSTree : public BTree<T>{
    void insert(const T &) override ;
    void remove(const T &) override ;
    void destory() override ;
    const T & find(const T &) override ;
};

template <typename T>
void BSTree::insert(const T &v) {
    if(!find(v)){

    }
}

template <typename T>
void BSTree::remove(const T &) {

}

template <typename T>
void BSTree::destory() {

}

template <typename T>
const T &BSTree::find(const T &) {
    return <#initializer#>;
}


#endif //CELL_BTREE_H
