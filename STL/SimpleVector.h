//
// Created by WJ on 2017/5/30.
//

#ifndef CELL_VECTOR_H
#define CELL_VECTOR_H

#include <memory>


template <typename T>
class SimpleVector{
public:
    typedef T value_type;
    typedef value_type * pointer;
    typedef value_type * iterator;
    typedef value_type & reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
private:
    std::allocator<T> alloc;
    iterator start;
    iterator finish;
    iterator end_of_storage;

public:
    SimpleVector():start(0),finish(0),end_of_storage(0){}
    SimpleVector(const SimpleVector<T> &v){
        auto newdata = alloc_n_copy(v.begin(), v.end());
        start = newdata.first;
        finish = end_of_storage = newdata.second;
    };
    ~SimpleVector(){ free();}
public:
    size_type size() const { return size_type (finish - start); }
    size_type capacity() const { return size_type (end_of_storage - start);}
    bool  empty() const { return finish == start;}
    T* begin() const { return start; }
    T* end() const { return finish;}
    void push_back(const T &v){
        chk_n_alloc();
        alloc.construct(finish++, v);
    }
private:

    void reallocate(){
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto s = start;

        for(size_t i = 0; i != size(); ++i){
            alloc.construct(dest++, std::move(*s++));
        }

        free();
        start = newdata;
        finish = dest;
        end_of_storage = start + newcapacity;
    };
    void free(){
        if(start){
            for( auto p = finish; p != start; ){
                alloc.destroy(--p);
            }

            alloc.deallocate(start , end_of_storage - start);
        }
    };
    std::pair<T* , T*> alloc_n_copy(const T*, const T*){
        auto data = alloc.allocate(finish - start);
        return {data, std::uninitialized_copy(start , finish , data)};
    };
    void chk_n_alloc(){ if(size() == capacity()) reallocate();}
};



#endif //CELL_VECTOR_H
