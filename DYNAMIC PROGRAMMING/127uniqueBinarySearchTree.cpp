/*
    Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly 
    n nodes of unique values from 1 to n.
    https://leetcode.com/problems/unique-binary-search-trees/description/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int solveMem(int n, vector<int>& dp){
        if(n<=1){
            return 1;
        } 

        if(dp[n]!=-1){
            return dp[n];
        }

        int ans = 0;
        
        for(int i = 1;i<=n;i++){
            // think every node as root node
            ans += solveMem(i-1, dp) * solveMem(n-i, dp);
        }
        return dp[n] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 1;

        for(int i=2;i<=n;i++){
            for(int j = 1; j<=i;j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
public:
    int numTrees(int n) {
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);
        return solveTab(n);
    }
};
