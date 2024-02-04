/*
    Delete Middle Element from Stack

    Recurrsion is used
*/

#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>&inputStack, int N,int count){
    // base case
    if(count==N/2){
        inputStack.pop();
        return;
    }
    int top = inputStack.top();
    inputStack.pop();

    count++;
    solve(inputStack,N,count);
    inputStack.push(top);
    return;

}
void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack,N,count);
}