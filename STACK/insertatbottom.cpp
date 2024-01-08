/*
    You are given a stack My stack. You have to insert a element at bottom of stack.
    Example: if Stack = [1,7,8] and element is 9, then after insertion
    Stack = [9,1,7,8]

*/
#include <iostream>
#include <stack>
using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }
    int top = myStack.top();
    myStack.pop();

    myStack = pushAtBottom(myStack,x);
    myStack.push(top);
    return myStack;
}
