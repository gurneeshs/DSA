/*
    Given a histogram, with length of rectangles and width = 1
    You have to find the max area of rectangles that can be formed in the histogram

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmaller(vector<int>& heights, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i =n-1;i>=0;i--){
        int curr = heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>& heights, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr = heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectanglearea(vector<int>& heights){
    int n = heights.size();
    vector<int> prev(n);
    prev = prevSmaller(heights,n);
    vector<int> next(n);
    next = nextSmaller(heights,n);

    int area = INT8_MIN;
    for(int i=0;i<n;i++){
        int l = heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b = next[i] - prev[i] -1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}