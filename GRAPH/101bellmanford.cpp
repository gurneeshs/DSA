/*
    You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each 
    edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
    Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.
    https://www.codingninjas.com/studio/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e8);
    dist[src] = 0;

    for(int i=1;i<n;i++){
        // traverse on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(((dist[u]+wt)<dist[v])){
                dist[v] = dist[u]+wt;
            }
        }
    }
    return dist;
}