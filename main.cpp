#include <iostream>
#include "Utils.h"

void add(int x ,int y, int *p){
    for(int i = 0; i < 100000000; i++ );
    *p = x + y;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    Utils utils;
    int p;
    utils.Runtime(add,1,2,&p);
    std::cout << p << std::endl;
    return 0;
}