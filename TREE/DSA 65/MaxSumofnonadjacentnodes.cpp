/*
    Given a binary tree with a value associated with each node, we need to choose a subset 
    of these nodes such that sum of chosen nodes is maximum under a constraint that no 
    two chosen node in subset should be directly connected that is, if we have taken a node 
    in our sum then we can’t take its any children or parents in consideration and vice versa.
    https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
