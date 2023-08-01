

#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

//
// Inorder traversal:
// Traverse left tree
// Visit root
// Traverse right tree
//
//
//
//
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res = {};
        traversal(root, res);
        return res;
    }
private:
    void traversal(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
};


int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> res;
    res = Solution().inorderTraversal(n1);

    for(int x : res)
        cout << x << " ";

}



