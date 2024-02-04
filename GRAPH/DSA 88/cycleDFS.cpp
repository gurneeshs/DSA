/*
    https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
    You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 
    to 'N'.

    Your task is to find if the graph contains a cycle or not.

    A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called 
    a cycle.
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
bool isCyclicDFS(int node, unordered_map<int,bool> &visited,unordered_map<int,list<int> > &adjList,vector<int> &component,int parent){
    
    component.push_back(node);
    visited[node] = 1;


    for(auto i:adjList[node]){
        if(!visited[i]){
            bool cycleDetected = isCyclicDFS(i,visited,adjList,component,node);
            if(cycleDetected){
                return true;
            }
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m){

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    // prepare adjacency list
    unordered_map<int,list<int> >adjList;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> component;
            bool ans = isCyclicDFS(i,visited,adjList, component, -1);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}