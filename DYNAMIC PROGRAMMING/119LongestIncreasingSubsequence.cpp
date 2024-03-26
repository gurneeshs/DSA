/*
    Given an array of integers, find the length of the longest (strictly) increasing subsequence from 
    the given array.
    https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int solve(int n, int a[], int curr, int prev){
        // base case
        if(curr==n){
            return 0;
        }
        // include
        int inc = 0;
        if(prev==-1 || a[curr]>a[prev]){
            inc = 1 + solve(n,a,curr+1,curr);
        }
        
        // exclude
        int exc = 0 + solve(n,a,curr+1,prev);
        
        return max(inc,exc);
    }
    int solveMem(int n, int *a, int curr, int prev, vector<vector<int> > &dp){
        // base case
        if(curr==n){
            return 0;
        }
        
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        // include
        int inc = 0;
        if(prev==-1 || a[curr]>a[prev]){
            inc = 1 + solveMem(n,a,curr+1,curr,dp);
        }
        
        // exclude
        int exc = 0 + solveMem(n,a,curr+1,prev,dp);
        
        dp[curr][prev+1] = max(inc,exc);
        return dp[curr][prev+1];
    }
    int solveTab(int n, int *a){
        vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
        
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int inc = 0;
                if(prev==-1 || a[curr]>a[prev]){
                    inc = 1 + dp[curr+1][curr+1];
                }
                
                // exclude
                int exc = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(inc,exc);
            }
        }    
        return dp[0][0];
    }
    int solveSO(int n, int *a){
        
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int inc = 0;
                if(prev==-1 || a[curr]>a[prev]){
                    inc = 1 + nextRow[curr+1];
                }
                
                // exclude
                int exc = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(inc,exc);
            }
            nextRow = currRow;
        }    
        return nextRow[0];
    }
    int solveOptimal(int n, int a[]){
        if(n==0)
            return 0;
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                // find index of just larger element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   return solve(n,a,0,-1);
    
        // vector<vector<int> > dp(n, vector<int>(n+1,-1));
        // return solveMem(n,a,0,-1,dp);
        
        // return solveTab(n,a);
        
        // return solveSO(n,a);
        
        solveOptimal(n,a);
    }
};