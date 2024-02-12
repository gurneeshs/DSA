/*
    You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the 
    number of strongly connected components (SCCs) present in the graph.

    A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. 
    The strongly connected components of a graph are the subgraphs which are themselves strongly connected.
    https://www.codingninjas.com/studio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
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

void dfs(int node,unordered_map<int,bool> &visited, stack<int> &st,	unordered_map<int,list<int> > &adj ){
	visited[node] = true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(nbr,visited,st,adj);
		}
	}
	st.push(node);
}
void revDfs(int node, unordered_map<int,bool> &visited, unordered_map<int,list<int> > &transpose){
	visited[node] = true;
	for(auto nbr:transpose[node]){
		if(!visited[nbr]){
			revDfs(nbr,visited,transpose);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int> > adj;
	unordered_map<int,bool> visited;

	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// topological sort
	stack<int> st;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,visited,st,adj);
		}
	}

	// transpores graph
	unordered_map<int,list<int> > transpose;
	for(int i=0;i<v;i++){
		visited[i] = 0;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	// call dfs using above ordering
	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();

		if(!visited[top]){
			count++;
			revDfs(top,visited,transpose);

		}
	}
	return count;	
}