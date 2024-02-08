/*
    https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

    You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices 
    (numbered from 0 to V-1) and E number of edges.

    Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

    By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted 
    undirected graph that connects all the vertices together, without any cycles and with the minimum 
    possible total edge weight.
*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
  return a[2]<b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0;i<n;i++){
    parent[i] = i;
    rank[i] = 0;
  }
}
int findParent(vector<int> &parent, int node){
  if(parent[node] == node){//Repeat until parent of element is element itself
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);//path compression
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u]<rank[v]){
    parent[u] = v;
  }
  else if(rank[v]<rank[u]){
    parent[v] = u;
  }
  else{
    parent[v] = u;
    rank[u]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent,rank,n);
  int weight = 0;

  for(int i = 0;i<edges.size();i++){
    int u = findParent(parent,edges[i][0]);
    int v = findParent(parent,edges[i][1]);
    int wt = edges[i][2];

    if(u!=v){
      weight += wt;
      unionSet(u, v, parent,rank);
    }
  }
  return weight;
}