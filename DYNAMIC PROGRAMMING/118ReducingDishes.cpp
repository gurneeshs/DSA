/*
    A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of 
    time.

    Like-time coefficient of a dish is defined as the time taken to cook that dish including previous 
    dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

    Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of 
    dishes.

    Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int solve(vector<int> &satisfaction, int pos, int time){
        // base case
        if(pos==satisfaction.size()){
            return 0;
        }

        int include = satisfaction[pos]*(time+1) + solve(satisfaction,pos+1,time+1);
        int exclude = 0 + solve(satisfaction, pos+1, time);

        return max(include,exclude);
    }
    int solveMem(vector<int> &satisfaction, int pos, int time, vector<vector<int> >&dp){
        // base case
        if(pos==satisfaction.size()){
            return 0;
        }

        if(dp[pos][time]!=-1){
            return dp[pos][time];
        }

        int include = satisfaction[pos]*(time+1) + solveMem(satisfaction,pos+1,time+1,dp);
        int exclude = 0 + solveMem(satisfaction, pos+1, time, dp);

        dp[pos][time] = max(include,exclude);

        return dp[pos][time];
    }
    int solveTab(vector<int> &satisfaction){
        int n = satisfaction.size();
        vector<vector<int> > dp(n+1, vector<int> (n+1,0));

        for(int pos = n-1;pos>=0;pos--){
            for(int time = pos;time>=0;time--){
                int include = satisfaction[pos]*(time+1) + dp[pos+1][time+1];
                int exclude = 0 + dp[pos+1][time];
                dp[pos][time] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int solveSO(vector<int> &satisfaction){
        int n = satisfaction.size();

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int pos = n-1;pos>=0;pos--){
            for(int time = pos;time>=0;time--){
                int include = satisfaction[pos]*(time+1) + next[time+1];
                int exclude = 0 + next[time];
                curr[time] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction, 0,0);

        // int n = satisfaction.size();
        // vector<vector<int> > dp(n+1,vector<int> (n+1, -1));
        // return solveMem(satisfaction,0,0,dp);

        // return solveTab(satisfaction);

        return solveSO(satisfaction);
    }
};