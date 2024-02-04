/*
    https://www.codingninjas.com/studio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
    The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

    Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

    Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
    1. They share a row. 
    2. They share a column. 
    3. They share a diagonal. 
*/
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}
bool isSafe(int row, int col , vector<vector<int>> &board, int n ){
	int x = row;
	int y = col;

	// check for same row
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}

	// diagonal check
	x = row;
	y = col;

	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	x = row;
	y = col;

	while(x<n && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}
	return true;
}
void solve(int col,	vector<vector<int>> &ans, vector<vector<int>> &board, int n){
	//base case
	if(col==n){
		addSolution(board, ans,n);
		return;
	} 

	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			// if placing queen is safe
			board[row][col] = 1;
			solve(col+1,ans,board,n);
			// backtracking
			board[row][col] = 0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	// Initialization of board
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0,ans,board,n);
	return ans;
	
}