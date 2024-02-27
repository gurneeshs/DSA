/*
    Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 
    'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

    Ninja wonders how many ways are there to do the above task, so he asked for your help.

    Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.
    https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#include <vector>
using namespace std;
int add(int a, int b){
    return ((a % MOD) + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD)*1LL * (b%MOD))%MOD;
}

int solve(int n, int k){
    // base cases
    if(n==1)
        return k;
    if(n==2)
        return add(k,mul(k,k-1));

    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
int solveMem(int n, int k, vector<int> &dp){
    // base cases
    if(n==1){
        dp[n] = k;
        return dp[n];
    }
    if(n==2){
        dp[n] = add(k,mul(k,k-1));
        return dp[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}
int solveTab(int n, int k){
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int solveSpace(int n, int k){
    int prev2 = k;
    int prev1 = add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        int ans = add(mul(prev2,k-1),mul(prev1,k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    // return solve(n,k);

    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp);

    // return solveTab(n, k);

    return solveSpace(n, k);
}
