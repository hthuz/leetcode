
#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
// pow
#include <math.h>
// Infinity
#include <limits>
// max_element
#include <algorithm>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

// From 655 print tree
class PrintTree {
public:
    vector<vector<string>> printTree(TreeNode* root);
private:
    int height;
    vector<vector<string>> res;
    void _printTree(TreeNode* root, int row, int col);
    int getHeight(TreeNode* root);
};

void print_stack(stack<char> st);
vector<vector<int>> init_2dvec(int m, int n, int init_val);
void print_2dvec(vector<vector<string>>& nums);
void print_2dvec(vector<vector<int>>& nums);
TreeNode* vec_to_tree(vector<int>& num);
void _bt_insert(int index, vector<int>& num, TreeNode* root);

ListNode* arr_to_list(int* array, int size);
void print_list(ListNode* head);

#endif


