/*
    Ninja is willing to take some time off from his training and planning a year-long tour. You are given a 
    DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an 
    integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
    A 1-day pass is sold for 'COST'[0] coins,
    A 7-day pass is sold for 'COST'[1] coins, and
    A 30-day  pass is sold for 'COST'[2] coins.
    The passes allow for many days of consecutive travel.
    Your task is to help the Ninja to find the minimum number of coins required to complete his tour. 
    For example,
    If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
    https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int solve(int n, vector<int> &days, vector<int> &cost, int index){
    // BASE CASE
    if(index>=n){
        return 0;
    }
    // 1 day pass
    int opt1 = cost[0] + solve(n, days, cost, index+1);
    
    // 7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int opt2 = cost[1] + solve(n,days,cost,i);

    // 30 day pass
    int j;
    for(j=index;j<n && days[j]<days[index]+30;j++);
    int opt3 = cost[2] + solve(n,days,cost,j);

    int ans = min(opt1,min(opt2,opt3));
    return ans;

}
int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    // BASE CASE
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    // 1 day pass
    int opt1 = cost[0] + solveMem(n, days, cost, index+1,dp);
    
    // 7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int opt2 = cost[1] + solveMem(n,days,cost,i,dp);

    // 30 day pass
    int j;
    for(j=index;j<n && days[j]<days[index]+30;j++);
    int opt3 = cost[2] + solveMem(n,days,cost,j,dp);

    int ans = min(opt1,min(opt2,opt3));
    dp[index] = ans; 
    return dp[index];

}
int solveTab(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1,INT_MAX);

    dp[n] = 0;

    for(int k=n-1;k>=0;k--){
        // 1 day pass
        int opt1 = cost[0] + dp[k+1];
        
        // 7 day pass
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int opt2 = cost[1] + dp[i];

        // 30 day pass
        int j;
        for(j=k;j<n && days[j]<days[k]+30;j++);
        int opt3 = cost[2] + dp[j];

        dp[k] = min(opt1,min(opt2,opt3));        
    }
    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    // return solve(n, days, cost, 0);

    // vector<int> dp(n+1,-1);
    // return solveMem(n, days, cost, 0, dp);

    return solveTab(n, days, cost);

}