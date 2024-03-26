/*
    Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.
    https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution{
    int solve(int i, int j, vector<vector<int>> &mat, int &maxi){
        // base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
            
        int right = solve(i,j+1,mat,maxi);
        int diagonal = solve(i+1,j+1,mat,maxi);
        int down = solve(i+1,j,mat,maxi);
        
        if(mat[i][j]==1){
            int ans = 1+min(right,min(diagonal,down));
            maxi = max(ans,maxi);
            return ans;
        }
        else{
            return 0;
        }

    }
    int solveMem(int i, int j, vector<vector<int>> &mat, int &maxi,vector<vector<int> > &dp){
        // base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }            
        int right = solveMem(i,j+1,mat,maxi,dp);
        int diagonal = solveMem(i+1,j+1,mat,maxi,dp);
        int down = solveMem(i+1,j,mat,maxi,dp);
        
        if(mat[i][j]==1){
            int ans = 1+min(right,min(diagonal,down));
            maxi = max(ans,maxi);
            dp[i][j] = ans;
            return dp[i][j];
        }
        else{
            dp[i][j]=0;
            return dp[i][j];
        }

    }
    int solveTab(vector<vector<int> > &mat, int &maxi){
        // create dp array
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int> > dp(row+1, vector<int> (col+1,0));
        
        for(int i = row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j]==1){
                    int ans = 1+min(right,min(diagonal,down));
                    maxi = max(ans,maxi);
                    dp[i][j] = ans;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][0];
    }
    int solveSO(vector<vector<int> > &mat, int &maxi){
        // create dp array
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int> > dp(row+1, vector<int> (col+1,0));
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        for(int i = row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j]==1){
                    int ans = 1+min(right,min(diagonal,down));
                    maxi = max(ans,maxi);
                    curr[j] = ans;
                }
                else{
                    curr[j]=0;
                }
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // int maxi = 0;
        // solve(0,0,mat,maxi);
        // return maxi;
        
        // int maxi = 0;
        // vector<vector<int> > dp(n,vector<int>(m,-1));
        // solveMem(0,0,mat,maxi,dp);
        // return maxi;
        
        // int maxi = 0;
        // solveTab(mat,maxi);
        // return maxi;
    
        int maxi = 0;
        solveSO(mat,maxi);
        return maxi;
    }
};