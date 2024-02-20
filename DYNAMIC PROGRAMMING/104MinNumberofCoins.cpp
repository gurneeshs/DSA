/*
    https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM'
    You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have 
    to tell the minimum number of elements you have to take to reach the target sum ‘X’.
*/
#include <bits/stdc++.h> 
#include <vector>
using namespace std;
int solveRec(vector<int> &num, int x){
    // base case
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveRec(num, x-num[i]);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int solveMem(vector<int> &num, int x,vector<int> &dp){
    // base case
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;
    if(dp[x]!=-1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveMem(num, x-num[i],dp);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    dp[x] = mini;
    return dp[x];
}
int solveTab(vector<int> &nums, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }

    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{                                                                                    
    // Approach 1: Recursion
    // int ans = solveRec(num, x);
    // if(ans==INT_MAX){
    //     return -1;

    // }
    // return ans;

    // Approach 2: Memorization
    // vector<int> dp(x+1,-1);
    // int ans = solveMem(num,x,dp);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    // return ans;

    // Approach 3: Tabulation
    return solveTab(num,x);
}
