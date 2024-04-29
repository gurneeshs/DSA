/*
    Given weights and values of n items, we need to put these items in a knapsack of capacity w to get 
    the maximum total value in the knapsack.
    https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
  public:
    static bool cmp(pair<double,Item> a, pair<double,Item> b){
        return a.first > b.first;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double, Item> > v;
        
        for(int i = 0;i<n;i++){
            double perUnit = (1.0*arr[i].value)/arr[i].weight;
            pair<double,Item> p = make_pair(perUnit, arr[i]);
            v.push_back(p);
            
        }
        
        sort(v.begin(),v.end(),cmp);
        
        double totalValue = 0;
        
        for(int i=0;i<n;i++ ){
            if(v[i].second.weight > w){
                totalValue += w*v[i].first;
                w = 0;
            }
            else{
                totalValue += v[i].second.value;
                w = w - v[i].second.weight;
            }
        }
        
        return totalValue;
        
    }
};