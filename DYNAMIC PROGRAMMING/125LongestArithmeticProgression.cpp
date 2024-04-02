/*
    Given an array called A[] of sorted integers having no duplicates, find the length of the Longest 
    Arithmetic Progression (LLAP) in it.
    https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
    
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{   
public:
    // int solve(int index, int diff, int A[]){
    //     // base case
    //     if(index<0){
    //         return 0;
    //     }
        
    //     int ans = 0;
    //     for(int j = index-1;j>=0;j--){
    //         if(A[index] - A[j]==diff){
    //             ans = max(ans, 1 + solve(j,diff,A));
    //         }
    //     }
    //     return ans;
    // }
    
    // int solveMem(int index, int diff, int A[], unordered_map<int, int> dp[]){
    //     // base case
    //     if(index<0){
    //         return 0;
    //     }
        
    //     if(dp[index].count(diff)){
    //         return dp[index][diff];
    //     }
        
    //     int ans = 0;
    //     for(int j = index-1;j>=0;j--){
    //         if(A[index] - A[j]==diff){
    //             ans = max(ans, 1 + solveMem(j,diff,A,dp));
    //         }
    //     }
    //     return dp[index][diff] = ans;
    // }
    
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2){
            return n;
        }
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans = max(ans, 2 + solve(i,A[j]-A[i], A));
        //     }
        // }
        
        // unordered_map<int,int> dp[n+1];
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans = max(ans, 2 + solveMem(i,A[j]-A[i], A, dp));
        //     }
        // }
        // return ans;
        
        vector<vector<int>> dp(n+1, vector<int>(A[n-1] - A[0] +1, INT32_MIN));
        
        for(int i=1 ; i<n ;i++){
            for(int j=0; j<i;j++)
            {
                int diff =A[i]-A[j];
                int cnt=1;
                if(dp[j][diff]!=INT32_MIN)
                    cnt=dp[j][diff];
                dp[i][diff]=cnt+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
        
    }
};