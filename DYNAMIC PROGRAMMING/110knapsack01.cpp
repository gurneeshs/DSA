/*
    A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the 
    ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack 
    can carry, you have to find and return the maximum value that a thief can generate by stealing items.
    https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (weight[index] <= maxWeight)
    {
        include = value[index] + solve(weight, value, index - 1, maxWeight - weight[index]);
    }
    int exclude = solve(weight, value, index - 1, maxWeight);

    int ans = max(include, exclude);
    return ans;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }
    int include = 0;
    if (weight[index] <= maxWeight)
    {
        include = value[index] + solveMem(weight, value, index - 1, maxWeight - weight[index], dp);
    }
    int exclude = solveMem(weight, value, index - 1, maxWeight, dp);

    int ans = max(include, exclude);
    dp[index][maxWeight] = ans;
    return dp[index][maxWeight];
}
int solveTab(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1:
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // step 2:
    // base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // step 3:
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index-1][w-weight[index]];
            }
            int exclude = dp[index-1][w];

            int ans = max(include, exclude);
            dp[index][w] = ans;
            return dp[index][maxWeight];
        }
    }

    return dp[n-1][maxWeight];
}
int solveSpace(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1:
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
    // step 2:
    // base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    // step 3:
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + prev[w-weight[index]];
            }
            int exclude = prev[w];

            int ans = max(include, exclude);
            curr[w] = ans;
        }
        prev = curr;
    }

    return prev[maxWeight];
}
int solveOpt(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1:
    vector<int> curr(maxWeight+1,0);
    // step 2:
    // base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    // step 3:
    for (int index = 1; index < n; index++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w-weight[index]];
            }
            int exclude = curr[w];

            int ans = max(include, exclude);
            curr[w] = ans;
        }
    }

    return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    // return solve(weight, value, n-1, maxWeight);

    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMem(weight, value, n - 1, maxWeight, dp);

    // return solveSpace(weight,value,n,maxWeight);
    return solveOpt(weight,value,n,maxWeight);
}

int main()
{
    return 0;
}