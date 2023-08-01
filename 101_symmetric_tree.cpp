
#include "utils.h"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode* left, TreeNode* right) {
        if(!left & !right)
            return true;
        if(!left ^ !right)
            return false;
        if(left->val != right->val)
            return false;
        return isSame(left->left, right->right) & isSame(left->right, right->left);
    }
};


int main()
{
    vector<int> num = {1,2,2};
    TreeNode* root = vec_to_tree(num);
    bool res = Solution().isSymmetric(root);
    cout << res << endl;
}
