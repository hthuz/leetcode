
#include "utils.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p ^ !q)
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left,q->left) & isSameTree(p->right, q->right);
    }
};

int main()
{
    vector<int> vec1 = {1,2};
    vector<int> vec2 = {1,NULLVAL,2};
    TreeNode* p = vec_to_tree(vec1);
    TreeNode* q = vec_to_tree(vec2);
    bool val = Solution().isSameTree(p,q);
    cout << val << endl;

}
