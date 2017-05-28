//
// Created by WJ on 2017/5/27.
//

#ifndef CELL_BINHEAP_H
#define CELL_BINHEAP_H


#include <vector>
#include <iostream>
#include "Heap.h"

template <typename T>
class BinHeap : public Heap<T>{


public:

    BinHeap<T>():_size(0){}
    BinHeap<T>(const std::initializer_list<T> &v);
    void insert(const T &e) override;
    void top() override;
    bool isEmpty() override;
    void levelOrder();
private:
    inline int left(int i){ return 2 * i; }
    inline int right(int i){ return 2 * i + 1;}
    inline int parent(int i){ return i / 2; }
    void up(int i);
    void down(int i);
    void swap(std::vector<T> &v, int i, int j);
    std::vector<T>  items;
    int _size;

};

template <typename T>
void BinHeap<T>::insert(const T &e) {
    items[++_size] = e;
    up(_size);
}



template <typename T>
void BinHeap<T>::top() {

}

template <typename T>
bool BinHeap<T>::isEmpty() {
    return _size == 0;
}

template <typename T>
void BinHeap<T>::up(int i) {
    int p;

    p = parent(i);

    while(i > 1 && items[i] > items[p]){
        swap(items, i, p);
        i = p;
        p = parent(i);
    }
}
template <typename T>
void BinHeap<T>::down(int i) {
    int l, r, largest;

    l = left(i);
    r = right(i);
    largest  = i;
    if(l <= _size && items[l] > items[largest]) largest = l;
    if(r <= _size && items[r] > items[largest]) largest = r;

    if(i != largest){
        swap(items, i, largest);
        down(largest);
    }
}


template <typename T>
void BinHeap<T>::swap(std::vector<T> &v, int i, int j) {
    auto t = v[i];
    v[i]  = v[j];
    v[j] = t;
}



template <typename T>
BinHeap<T>::BinHeap(const std::initializer_list<T> &v):_size(v.size()) {
    items.push_back(T());
    for(auto &i: v){
        items.push_back(i);
    }

    for(int i = _size / 2; i > 0; i--){
        down(i);
    }
}

template <typename T>
void BinHeap<T>::levelOrder() {

    for(int i = 1; i <= _size; i++){
        std::cout << items[i] << " ";
    }
}


#endif //CELL_BINHEAP_H
