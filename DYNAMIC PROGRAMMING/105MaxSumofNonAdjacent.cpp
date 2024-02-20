/*
    You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence 
    with the constraint that no two elements are adjacent in the given array/list.

    Note:
    A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the 
    array/list, leaving the remaining elements in their original order.
    https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <bits/stdc++.h> 
#include <vector>
using namespace std;
int solve(vector<int> &nums, int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1);
    return max(incl, excl);
}

int solveMem(vector<int> &nums, int n,vector<int> &dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1);
    dp[n] = max(incl, excl);
    return dp[n];
}

int solveVar(vector<int> &nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1;i<n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // int n  = nums.size();
    // vector<int> dp(n,-1);
    // return solveMem(nums,n-1,dp);
    // return solveTab(nums);
    return solveVar(nums);
}