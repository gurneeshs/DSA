/*
    Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the 
    given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph 
    disconnected (or more precisely, increases the number of connected components in the graph).

    https://www.codingninjas.com/studio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void dfs(int node, int &parent,int timer,vector<int> &disc,vector<int> &low,unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,vector<vector<int> > &result){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    // visiting adjacent node
    for(auto nbr :adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr, node, timer, disc, low, adj, visited, result);
            low[node] = min(low[node],low[nbr]);

            // check if bridge
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // back edge
            low[node] = min(low[node],disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    unordered_map<int,list<int> > adj;
    vector<vector<int> > result;
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int,bool> visited;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }

    // DFS
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,disc,low,adj,visited,result);
        }
    }
    return result;
}