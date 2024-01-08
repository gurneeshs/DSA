/*
   Given a binary tree of size  N, a node, and a positive integer k., 
   Your task is to complete the function kthAncestor(), the function should 
   return the kth ancestor of the given node in the binary tree. If there 
   does not exist any such ancestor then return -1.
    https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};
