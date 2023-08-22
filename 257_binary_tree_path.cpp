

#include "utils.h"


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        string val = to_string(root->val);
        if(!root->left && !root->right)
            return {val};

        vector<string> subpath = {};
        vector<string> path = {};
        if(root->left) {
            subpath = binaryTreePaths(root->left);
            for(vector<string>::iterator itr = subpath.begin(); itr != subpath.end(); itr++)
                path.push_back(val + "->" + *itr);
        }
        if(root->right) {
            subpath = binaryTreePaths(root->right);
            for(vector<string>::iterator itr = subpath.begin(); itr != subpath.end(); itr++)
                path.push_back(val + "->" + *itr);
        }

        return path;
    }
};

int main()
{
    
    vector<int> num = {1};
    TreeNode* root = vec_to_tree(num);
    vector<string> ans = Solution().binaryTreePaths(root);
    for(string x : ans)
        cout << x << endl;
    

}
