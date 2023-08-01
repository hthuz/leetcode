
#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
#include <stack>
using namespace std;


void print_stack(stack<char> st);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif
