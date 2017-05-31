//
// Created by WJ on 2017/5/30.
//

#ifndef CELL_TUPLE_H
#define CELL_TUPLE_H
template <typename... TList> struct Tuple;

template <> struct Tuple<>{};
typedef Tuple<> nullTuple;

template <typename T, typename ... TList>
struct Tuple<T, TList...> : public Tuple<TList...>
{
    typedef T value_type;
    typedef Tuple<TList...> base_type;
public:
    Tuple(const T& v,const  TList&... tails):_value(v),base_type(tails...){}
    const T& head() const { return this->_value; }

protected:
    T _value;
};

template <unsigned int N, typename ...TList> struct Tuple_At;


template <typename T>
struct Tuple<T> : public nullTuple{
    typedef T value_type;
    typedef Tuple<T> base_type;
    Tuple(const T& v):_value(v){}

protected:
    T _value;

};

#endif //CELL_TUPLE_H
