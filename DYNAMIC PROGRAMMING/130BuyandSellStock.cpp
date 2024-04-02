/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
    in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, 
    return 0.
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;

        for(int i=1;i<n;i++){
            int diff = prices[i] - mini;
            if(diff>=0){
                profit = max(profit,diff);
            }
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};