/*
    Given an integer array arr and an integer difference, return the length of the longest subsequence in arr 
    which is an arithmetic sequence such that the difference between adjacent elements in the subsequence 
    equals difference.

    A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing 
    the order of the remaining elements.
    https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int tempAns = 0;

            // if temp already present
            if(dp.count(temp)){
                tempAns = dp[temp];
            }

            dp[arr[i]] = 1 + tempAns;
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};