/*
    You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ 
    of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] 
    to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for 
    each edge in the MST.
    https://www.codingninjas.com/studio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;//<u, list<v,w>>
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    vector<pair<pair<int, int>, int>> ans;

    // 1. Create Adjacency List
    for(int i=0;i<m;i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // 2. Initialize Vectors
    for(int i=0;i<=n;i++){
        key[i] = INT32_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // 3. 
    key[1] = 0;
    parent[1] = -1;

    for(int i=1;i<=n;i++){
        int mini = INT32_MAX;
        int u;

        // find min value node
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        // check its adjacent nodes;
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;

            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    for(int i=2;i<=n;i++){
        ans.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return ans;


}

