/*
    https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents 
    the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

    Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed 
    graph else return false.
*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int,bool> &dfsVisited,unordered_map<int, list<int> > &adj ){
  
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected = isCyclicDFS(neighbour,visited,dfsVisited,adj);
      if(cycleDetected){
        return true;
      }
    }
    else if(dfsVisited[neighbour]){
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;

}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int, list<int> > adj;
  unordered_map<int, bool> visited;
  unordered_map<int,bool> dfsVisited;
  // Prepare List
  for(int i=0;i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound = isCyclicDFS(i,visited,dfsVisited,adj);
      if(cycleFound){
        return true;
      }
    }
  }
  return false;
}