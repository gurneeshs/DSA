/*
    https://www.codingninjas.com/studio/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    You are given an array of distinct integers and you have to tell how many different ways of selecting 
    the elements from the array are there such that the sum of chosen elements is equal to the target number tar.

    Note: Two ways are considered the same if for every index the contents of both the ways are equal example 
    way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

    But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

    Input is given such that the answer will fit in a 32-bit integer. For Example:
    If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 
    are:
    (1,1,1,1,1)
    (1,1,1,2)
    (1,2,1,1)
    (2,1,1,1)
    (1,1,2,1)
    (2,2,1)
    (1,2,2)
    (2,1,2)
    (5)
    Hence the output will be 9.
*/
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums,int tar){
    // base case
    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans += solve(nums,tar-nums[i]);
    }
    return ans;

}
int solveMem(vector<int> &nums, int tar,vector<int> &dp ){
    // base case
    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans += solveMem(nums,tar-nums[i],dp);
    }
    dp[tar] = ans;
    return dp[tar];
    
}
int solveTab(vector<int> &nums, int tar){
    vector<int> dp(tar+1,0);

    dp[0] = 1;

    for(int i=1;i<=tar;i++){
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0){
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    // RECURSIVE SOLUTION
    // return solve(num, tar);

    // MEMORIZATION
    // vector<int> dp(tar+1,-1);
    // return solveMem(num, tar, dp);
    // TABULATION

    return solveTab(num, tar);
}

int main(){
    return 0;
}