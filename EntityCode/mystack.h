#ifndef MYSTACK_H
#define MYSTACK_H

#include<stack>
using namespace std;


    /**
    @class MyStack
    @brief A simplified encapsulated stl::stack.  Allows for elements to be
    added to the top, returned and removed from the top, and checks if the stack
    is empty.

    @author Chris
    @date 3/10/2017
    @version 1

    @bug No bugs

    */
template <class T>
class MyStack{

public:
        /**
        @brief Adds a new element on the top of the stack

        @param T, the element to be added
        */
    void push(T ele);

        /**
        @brief Returns and removes the top element of the stack

        @retval const T (the top element of the stack; now removed
        */
    const T pop();

        /**
        @brief Returns 1 if the stack is empty, 0 otherwise

        @retval 1 or 0
        */
    bool isEmpty();


private:
        ///stl::stack
    stack<T> myStack;


};


template <class T> void MyStack<T>::push(T ele)
{
    myStack.push(ele);
}

template <class T> const T MyStack<T>::pop()
{
    T temp;
    temp = myStack.top();
    myStack.pop();
    return temp;
}

template <class T> bool MyStack<T>::isEmpty()
{
    return myStack.empty();
}
#endif // STACK_H
