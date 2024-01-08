/*
    Given a array of size N, you have to return the first smaller element for 
    each element array. if smaller element is not found, return -1

    E.g: I/p = [2,1,4,3]
         O/p = [1,-1,3,-1]
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i =n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> ip;
    ip.push_back(2);
    ip.push_back(1);
    ip.push_back(4);
    ip.push_back(3);

    vector<int> op(4);
    op = nextSmallerElement(ip, 4);

    for(int itm:op){
        cout<<itm<<" ";
    }
    return 0;
}