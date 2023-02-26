//
// Created by Omar Abd-Elhamid on 2/22/23.
//

#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

int main(){
    Stack<int> teststack;

    cout << teststack.empty() << endl;

    teststack.push(1);
    teststack.push(2);

    cout << teststack.top() << teststack.empty() << endl;
    teststack.pop();

    cout << teststack.top() << endl;
    teststack.pop();

    cout << teststack.empty();

    return 0;
}
