
#include "utils.h"

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        // Initialize
        this->height = getHeight(root);
        int col_num = pow(2,this->height + 1) - 1;
        for(int i = 0; i < this->height + 1; i++){
            vector<string> empty_row(col_num,"");
            this->res.push_back(empty_row);
        }

        // Fill in fields
        _printTree(root, 0, col_num / 2);
        // print_2dvec(res);
        return this->res;
    }
private:
    int height;
    vector<vector<string>> res;
    void _printTree(TreeNode* root, int row, int col) {

        if(!root)
            return;

        res[row][col] = to_string(root->val);

        int offset = pow(2, this->height - row - 1);
        _printTree(root->left, row + 1, col - offset);
        _printTree(root->right, row + 1, col + offset);
    };
    // root is at height 0
    int getHeight(TreeNode* root) {
        if(!root)
            return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};





int main()
{
    vector<int> num = {1,2,3,NULLVAL,4};
    Solution().printTree(vec_to_tree(num));

}
