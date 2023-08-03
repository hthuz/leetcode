

#include "utils.h"


void print_stack(stack<char> st)
{
    cout << "Top-> ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void print_2dvec(vector<vector<string>>& nums)
{
    for(vector<string> one_vec : nums)    
    {
        cout << "[";
        for(string x : one_vec)
            if (x == "")
                cout << " " << ",";
            else
                cout << x << ",";
        cout << "]\n";
    }
}

TreeNode* vec_to_tree(vector<int>& num)
{
    TreeNode* root = new TreeNode(num[0]);
    _bt_insert(0,num, root);

    return root;
}

void _bt_insert(int index,vector<int>& num, TreeNode* root)
{
    // cout << (root == nullptr ? NULLVAL : root->val) << endl;
    if (!root)
        return;
    if (index * 2 + 1 < num.size())
    {
        root->left = num[index * 2 + 1] == NULLVAL ? nullptr : new TreeNode(num[index * 2 + 1]);
        _bt_insert(index * 2 + 1, num, root->left);
    }
    if (index * 2 + 2 < num.size())
    {
        root->right = num[index * 2 + 2] == NULLVAL ? nullptr : new TreeNode(num[index * 2 + 2]);
        _bt_insert(index * 2 + 2, num, root->right);
    }
}




