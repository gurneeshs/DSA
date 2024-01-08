/*
    Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
    A path may start from any node and end at any node in the downward direction.
    https://www.geeksforgeeks.org/problems/k-sum-paths/1

*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
