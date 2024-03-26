/*
    Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] 
    (0-indexed). Choose a subset of cuboids and place them on each other.

    You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
    You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

    Return the maximum height of the stacked cuboids.
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& base, vector<int>& newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){
            return true;
        }
        return false;
    }
    int solve(int n, vector<vector<int> >&a){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);

        for(int curr = n-1; curr>=0 ; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev == -1 || check(a[curr],a[prev])){
                    take = a[curr][2] + nextRow[curr+1];

                }

                int notTake = 0 + nextRow[prev+1];
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }

        // Sort all Cuboids
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids.size(),cuboids);
    }
};