
#include "utils.h"


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_val = preorder[0];
        int index = linear_search(root_val, inorder);
        TreeNode* root = new TreeNode(root_val);
        if (inorder.size() == 1)
            return root;
        
        vector<int> left_preorder(preorder.begin() + 1,preorder.begin() + 1 + index);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        if(!left_preorder.empty() && !left_inorder.empty())
            root->left = buildTree(left_preorder, left_inorder);

        vector<int> right_preorder(preorder.begin() + 1 + index, preorder.end());
        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        if(!right_preorder.empty() && !right_inorder.empty())
            root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
private:
    // Return index in nums
    int linear_search(int val, vector<int>& nums) { 
        int len = nums.size();
        for(int i = 0; i < len; i++) 
            if(nums[i] == val)
                return i;
        return -1;
    }
};


int main() 
{
    // vector<int> pre = {3,9,20,15,7};
    // vector<int> in = {9,3,15,20,7};
    vector<int> pre = {1,2};
    vector<int> in = {2,1};

    TreeNode* root = Solution().buildTree(pre, in);
    PrintTree().printTree(root);

}
