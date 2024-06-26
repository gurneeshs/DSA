/*
    Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. 
    X is the summation of values on each face when all the dice are thrown.
    https://www.geeksforgeeks.org/problems/dice-throw5349/1
    

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int dice, int faces, int target){
        // base case
        if(target<0){
            return 0;
        }
        
        if(dice==0 && target!=0){
            return 0;
        }
        
        if(target==0 && dice!=0){
            return 0;
        }
        
        if(dice==0 && target==0){
            return 1;
        }
        
        long long ans = 0;
        for(int i=1;i<=faces;i++){
            ans = ans + solve(dice-1, faces, target-i);
        }
        return ans;
    }
    
    long long solveMem(int dice, int faces, int target, vector<vector<long long>>& dp){
        // base case
        if(target<0){
            return 0;
        }
        
        if(dice==0 && target!=0){
            return 0;
        }
        
        if(target==0 && dice!=0){
            return 0;
        }
        
        if(dice==0 && target==0){
            return 1;
        }
        
        if(dp[dice][target]!=-1){
            return dp[dice][target];
        }
        
        long long ans = 0;
        for(int i=1;i<=faces;i++){
            ans = ans + solveMem(dice-1, faces, target-i, dp);
        }
        dp[dice][target] =ans;
        return dp[dice][target];
    }
    
    long long solveTab(int d, int f, int t){
        vector<vector<long long> > dp(d+1 ,vector<long long> (t+1, 0));
        
        // Analyzing Base Case
        dp[0][0] = 1;
        
        for(int dice = 1; dice<= d; dice++){
            for(int target=1; target<=t;target++){
                long long ans = 0;
                for(int i=1;i<=f;i++){
                    if(target-i>=0){
                        ans = ans + dp[dice-1][target-i];                        
                    }

                }
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t];
    }
    
    long long solveSO(int d, int f, int t){
        
        vector<long long> prev(t+1,0);
        vector<long long> curr(t+1,0);

        // Analyzing Base Case
        prev[0] = 1;
        
        for(int dice = 1; dice<= d; dice++){
            for(int target=1; target<=t;target++){
                long long ans = 0;
                for(int i=1;i<=f;i++){
                    if(target-i>=0){
                        ans = ans + prev[target-i];                        
                    }

                }
                curr[target] = ans;
            }
            prev = curr;
        }
        
        return curr[t];
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        // return solve(N,M,X);
        
        // vector<vector<long long> > dp(N+1, vector<long long>(X+1, -1));
        // return solveMem(N,M,X,dp);
        
        // return solveTab(N,M,X);
        
        return solveSO(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends