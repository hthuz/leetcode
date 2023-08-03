

#include "utils.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode* root_left = root->left;
        root->left = root->right;
        root->right = root_left;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main()
{
    vector<int> num = {2,1,3};
    TreeNode* root = vec_to_tree(num);
    PrintTree().printTree(root);
    root = Solution().invertTree(vec_to_tree(num));
    PrintTree().printTree(root);
}
