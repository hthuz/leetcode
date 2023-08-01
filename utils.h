
#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


#define NULLVAL -1000

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_stack(stack<char> st);
TreeNode* vec_to_tree(vector<int>& num);
void _bt_insert(int index, vector<int>& num, TreeNode* root);

#endif


