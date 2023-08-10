

#include "utils.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return _sortedArrayToBST(0, nums.size());
    }
private:
    vector<int> nums;
    TreeNode* _sortedArrayToBST(int left, int right) {
        if( left >= right)
            return nullptr;

        int mid = (left + right ) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(left, mid);
        root->right = _sortedArrayToBST(mid + 1, right);
        return root;
    }
};


int main() 
{
    vector<int> nums = {1,3};
    TreeNode* root = Solution().sortedArrayToBST(nums);
    PrintTree().printTree(root);
}
