/*
    You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
    https://www.codingninjas.com/studio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> visited,vector < vector < int >> & arr,int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]!=1 && arr[x][y]==1 ){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x, int y,vector < vector < int >> & arr, int n, vector<string> &ans,vector<vector<bool>> visited, string path ){
    // base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    // Down
    if(isSafe(x+1,y,visited,arr,n)){
        visited[x][y] = 1;
        solve(x+1,y,arr,n,ans,visited,path + "D");
        visited[x][y] = 0;
    }
    // Left
    if(isSafe(x,y-1,visited,arr,n)){
        visited[x][y] = 1;
        solve(x,y-1,arr,n,ans,visited,path + "L");
        visited[x][y] = 0;
    }    
    // Right
    if(isSafe(x,y+1,visited,arr,n)){
        visited[x][y] = 1;
        solve(x,y+1,arr,n,ans,visited,path + "R");
        visited[x][y] = 0;
    }    
    // Up
    if(isSafe(x-1,y,visited,arr,n)){
        visited[x][y] = 1;
        solve(x-1,y,arr,n,ans,visited,path + "U");
        visited[x][y] = 0;
    }
}   
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool> (n,0));
    string path = "";

    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}