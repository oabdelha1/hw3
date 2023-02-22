#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    int ticker;
};

template <typename T>
Stack::Stack<T>() : vector<T> {
    ticker = 0;
}

template <typename T>
bool Stack<T>::empty() const{
    return this->size() == ticker;
}

template <typename T>
size_t Stack<T>::size(){
    return vector<T>::size() - ticker;
}

template <typename T>
void Stack<T>::pop(){
    ticker++;
}

template <typename T>
const T& Stack<T>::top() const{
    return vectror<T>[ticker];
}

#endif