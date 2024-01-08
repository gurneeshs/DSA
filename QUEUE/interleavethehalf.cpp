/*
    Given a Queue, you have to interleave the first half and second half
    using stack.
    E.g: Q = [10,11,12,13,14,15]
    Ans: Q = [10,13,11,14,12,15]
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> interleaveTheHalf(queue<int> q){
    int n = q.size();
    stack<int> s;

    for(int i=0;i<n/2;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    for(int i=0;i<n/2;i++){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    for(int i=0;i<n/2;i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for(int i=0;i<n/2;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

void printQueue(queue<int> q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int val = q.front();
        cout<<val<<" ";
        q.pop();
        q.push(val);
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    printQueue(q);
    q = interleaveTheHalf(q);
    printQueue(q);
    
    return 0;
}