/*
    Given two strings word1 and word2, return the minimum number of operations required to convert
    word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
    https://leetcode.com/problems/edit-distance/description/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    int solve(string a, string b, int i, int j){
        // base case
        if(i==a.length()){
            // word1 is less than word 2
            return b.length() - j;
        }
        if(j==b.length()){
            return a.length() - i;
        }

        int ans = 0;

        if(a[i]==b[j]){
            ans = solve(a,b,i+1,j+1);
        }
        else{
            // insert Ans
            int insertAns = 1 + solve(a,b,i,j+1);
            // delete Ans
            int deleteAns = 1 + solve(a,b,i+1,j);
            // replace Ans
            int replaceAns = 1 + solve(a,b,i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
    int solveMem(string a, string b, int i, int j, vector<vector<int> >& dp){
        // base case
        if(i==a.length()){
            // word1 is less than word 2
            return b.length() - j;
        }
        if(j==b.length()){
            return a.length() - i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;

        if(a[i]==b[j]){
            ans = solveMem(a,b,i+1,j+1,dp);
        }
        else{
            // insert Ans
            int insertAns = 1 + solveMem(a,b,i,j+1,dp);
            // delete Ans
            int deleteAns = 1 + solveMem(a,b,i+1,j,dp);
            // replace Ans
            int replaceAns = 1 + solveMem(a,b,i+1, j+1,dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string a, string b){
        int len1 = a.length();
        int len2 = b.length();

        vector<vector<int> >dp(len1+1, vector<int>(len2+1, 0));

        // analyzing base case
        for(int j = 0; j<len2;j++){
            dp[len1][j] = len2 - j;
        }
        for(int i = 0; i<len1;i++){
            dp[i][len2] = len1 - i;
        }

        for(int i = len1-1;i>=0;i--){
            for(int j = len2-1;j>=0;j--){
                int ans = 0;

                if(a[i]==b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    // insert Ans
                    int insertAns = 1 + dp[i][j+1];
                    // delete Ans
                    int deleteAns = 1 + dp[i+1][j];
                    // replace Ans
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];


    }
    int solveSO(string a, string b){


        int len1 = a.length();
        int len2 = b.length();

        if(len1==0){
            return len2;
        }
        if(len2==0){
            return len1;
        }

        // vector<vector<int> >dp(len1+1, vector<int>(len2+1, 0));
        vector<int> curr(len2+1, 0);
        vector<int> next(len2+1, 0);

        // analyzing base case
        for(int j = 0; j<len2;j++){
            next[j] = len2 - j;
        }
        // for(int i = 0; i<len1;i++){
        //     dp[i][len2] = len1 - i;
        // }

        for(int i = len1-1;i>=0;i--){
            for(int j = len2-1;j>=0;j--){
                curr[len2] = len1 - i;//from 2nd base case
                int ans = 0;

                if(a[i]==b[j]){
                    ans = next[j+1];
                }
                else{
                    // insert Ans
                    int insertAns = 1 + curr[j+1];
                    // delete Ans
                    int deleteAns = 1 + next[j];
                    // replace Ans
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];


    }
    int minDistance(string word1, string word2) {
        // return solve(word1, word2, 0, 0);

        // vector<vector<int> >dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(word1, word2, 0, 0, dp);

        // return solveTab(word1, word2);
        
        return solveSO(word1, word2);
    }
};