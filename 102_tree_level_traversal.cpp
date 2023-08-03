
#include "utils.h"

// Level order traversal of tree. i.e. transfrom tree to array.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        res = {};
        _levelOrder(root, 0);
        // print_2dvec(res);
        return res;
    }
private:
    vector<vector<int>> res;
    void _levelOrder(TreeNode* root, int row) {
        if(!root)
            return;
        if (row >= res.size())
            res.push_back({});
        res[row].push_back(root->val);
        _levelOrder(root->left,row + 1);
        _levelOrder(root->right,row + 1);
    }
};

int main()
{
    vector<int> num = {3,9, 20, NULLVAL, NULLVAL, 15, 7};
    Solution().levelOrder(vec_to_tree(num));

}
