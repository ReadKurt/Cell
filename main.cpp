#include <iostream>
#include "STL/SimpleVector.h"
using  namespace std;

int main() {

    SimpleVector<int> V;
    V.push_back(8);
    V.push_back(5);
    V.push_back(6);
    V.push_back(2);

    for(auto it = V.begin(); it != V.end(); it++){
        cout << *it << " \n";
    }
    return 0;
}