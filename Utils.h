//
// Created by WJ on 2017/5/27.
//

#ifndef CELL_UTILS_H
#define CELL_UTILS_H

#include <chrono>
#include <iostream>

class Utils{
public:
    template <typename F, typename... Args>
    void Runtime(const F f, const Args&... args);

    void Error();
};

template<typename F, typename... Args>
void Utils::Runtime(const F f, const Args &... args) {
    auto start = std::chrono::system_clock::now();
    f(args...);
    auto end   = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000;
    std::cout << "RunTime: " << duration << " ms"<< std::endl;
}

#endif //CELL_UTILS_H
