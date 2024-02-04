/*
    Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the 
    information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and 
    GRAPH[i][1]. print its DFS traversal.

    V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

    E is the number of edges present in graph G.
    Note :
    The Graph may not be connected i.e there may exist multiple components in a graph.
*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
void dfs(int node, unordered_map<int,bool> &visited,unordered_map<int,list<int> > &adjList,vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    
    // prepare adjacency list
    unordered_map<int,list<int> >adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}