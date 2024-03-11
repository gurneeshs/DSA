/*
    Given a number N. Find the minimum number of squares of any number that sums to N. For Example: 
    If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will 
    be 1 as minimum number of square is 1 , i.e (10*10).
    https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    private:
    int solve(int n){
        // base case
        if(n==0){
            return 0;
        }
        int ans = n;
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+solve(n-(i*i)));
        }
        return ans;
    }
    int solveMem(int n, vector<int> &dp){
        // base case
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = n;
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+solveMem(n-(i*i), dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    int solveTab(int n){
        vector<int> dp(n+1,INT_MAX);
        
        dp[0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                int temp = j*j;
                if(i-temp>=0){
                    dp[i] = min(dp[i], 1+dp[i-temp]);
                }
            }
        }
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{
	    // Code here
	   // return solve(n);
	   
	   //vector<int> dp(n+1,-1);
	   //return solveMem(n,dp);
	   
	   return solveTab(n);
	}
};