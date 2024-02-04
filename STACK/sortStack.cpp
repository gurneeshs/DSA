/*
    WAP to sort the stack
*/

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    printStack(st);
    cout<<top<<" ";
    st.push(top);
}
void insertSortStack(stack<int>& st, int el){
    if(st.empty()){
        st.push(el);
        return;
    }
    if(st.top()>el){
        int top  = st.top();
        st.pop();
        insertSortStack(st,el);
        st.push(top);
        return;
    }
    if(st.top()<=el){
        st.push(el);
        return;
    }
}
void sortStack(stack<int>& st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSortStack(st,top);

}
int main(){
    stack<int> st;
    st.push(5);
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(3);
    printStack(st);
    // insertSortStack(st,5);
    cout<<endl;
    sortStack(st);
    printStack(st);

    return 0;

}
