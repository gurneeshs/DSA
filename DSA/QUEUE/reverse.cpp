#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
    public:
    void reverse(queue<int>& q){
        if(q.empty()){
            return;
        }
        int element = q.front();
        q.pop();
        
        reverse(q);
        q.push(element);
    }
    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
        // stack<int> s;
        // while(!q.empty()){
        //     s.push(q.front());
        //     q.pop();
        // }
        // while(!s.empty()){
        //     q.push(s.top());
        //     s.pop();
        // }
        // return q;
        
        
    }
};


