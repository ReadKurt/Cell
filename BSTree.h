//
// Created by WJ on 2017/5/27.
//

#ifndef CELL_BSTREE_H
#define CELL_BSTREE_H

#include <iostream>
#include "BinTree.h"


template <typename T>
class BSTree : public BinTree<T>{
public:

    struct Node{
        T value;
        Node *left, *right;
        Node(const T &v):left(nullptr),right(nullptr),value(v){}
    };
    typedef Node* Tree;

public:
    BSTree<T>(const std::initializer_list<T> &list):root(nullptr), _size(0){

        for(auto &i: list){
            insert(i);
        }
    }
    BSTree<T>():root(nullptr), _size(0){};
private:
    Tree treeinsert(Tree tree, const T &v);
    Tree treeremove(Tree tree, const T &v);
    Tree treedestroy(Tree tree);
    Tree findMin(Tree tree);
    void preorder(Tree tree);
    bool isempty(Tree tree){ return tree == nullptr;}
public:
    void insert(const T &) override ;
    void remove(const T &) override ;
    bool isEmpty(){ return _size == 0;}
    void preOrder();
    size_t size(){ return _size;}
    ~BSTree(){ destroy(); }

private:
    void destroy() ;
private:
    Tree root;
    size_t _size;
};

template <typename T>
typename BSTree<T>::Tree BSTree<T>::treeinsert(BSTree<T>::Tree tree, const T &v) {

    if(isempty(tree)){
        _size++;
        return new Node(v);
    }

    if(tree->value > v){
        tree->left =  treeinsert(tree->left, v);

    }else if(tree->value < v){
        tree->right =  treeinsert(tree->right,v);

    }else{
        std::cout << v << " has existed!\n";
    }

    return tree;
}

template <typename T>
typename BSTree<T>::Tree BSTree<T>::treeremove(BSTree<T>::Tree tree, const T &v) {

    Tree t;

    if(isempty(tree))
        return nullptr;

    if(tree->value > v)
        tree->left = treeremove(tree->left, v);
    else if(tree->value < v){
        tree->right = treeremove(tree->right, v);
    }else{
        Tree min;
        if(tree->left && tree->right){
            min = findMin(tree->right);
            tree->value = min->value;
            tree->right = treeremove(tree->right, min->value);
            delete min;

        }else{
            if(isempty(tree->left)) tree = tree->right;
            else tree = tree->left;
        }
        _size--;
        return tree;
    }


}

template <typename T>
typename BSTree<T>::Tree BSTree<T>::treedestroy(BSTree<T>::Tree tree) {
    if(!isempty(tree)){
        treedestroy(tree->left);
        treedestroy(tree->right);
        delete tree;
    }
}



template <typename T>
typename BSTree<T>::Tree BSTree<T>::findMin(BSTree::Tree tree) {
    if(isempty(tree))
        return nullptr;
    else if(isempty(tree->left))
        return tree;
    else findMin(tree->left);
}

template <typename T>
void BSTree<T>::preorder(BSTree<T>::Tree tree) {
    if(!isempty(tree)){
        std::cout << tree->value << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

template <typename T>
void BSTree<T>::insert(const T &v) {
    root = treeinsert(root, v);
}

template <typename T>
void BSTree<T>::remove(const T &v) {
    root = treeremove(root, v);
}

template <typename T>
void BSTree<T>::destroy() {
    root = treedestroy(root);
}



template <typename T>
void BSTree<T>::preOrder() {
    std::cout << "\n";
    preorder(root);
    std::cout << "\n";
}


#endif //CELL_BSTREE_H
