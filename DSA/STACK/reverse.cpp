/*
    Given a stack, You have to reverse the stack
*/
#include <iostream>
#include <stack>
using namespace std;

stack<int> insert(stack<int> st, int x){
    // base case
    if(st.empty()){
        st.push(x);
        return st;
    }
    int top = st.top();
    st.pop();

    st = insert(st,x);
    st.push(top);
    return st;
}

stack<int> reverse(stack<int> st){
    if(st.empty()){
        return st;
    }
    int top = st.top();
    st.pop();
    st = reverse(st);
    st = insert(st,top);
    return st;
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(7);

    // cout<<st;
    return 0;
}