/*
    https://www.codingninjas.com/studio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
    
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col,vector<vector<int>>& board ,int val){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==val){
            // row check
            return false;
        }
        if(board[i][col]==val){
            // column check
            return false;
        }
        if(board[3*(row/3 + i/3)][3*(col/3) + i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& board){
    int n = board[0].size();

    for(int row = 0;row<n;row++){
        for(int col = 0;col<n;col++){
            // if cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;

                        bool Solution = solve(board);
                        if(Solution){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
} 
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku);
}
void printBoard(vector<vector<int>>& arr){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> arr;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }

    // printBoard(arr);
    // solveSudoku(arr);
    // printBoard(arr);
    return 0;
}