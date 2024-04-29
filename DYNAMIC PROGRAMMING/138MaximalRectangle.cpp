/*
    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing 
    only 1's and return its area.
    https://leetcode.com/problems/maximal-rectangle/description/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
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
    int largestRectangleArea(vector<int>& heights){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT32_MIN;
        vector<int> histogram(matrix[0].size(), 0);

        for(int i = 0;i<matrix.size();i++){
            // To Create Histogram Array
            for(int j = 0; j<histogram.size();j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};