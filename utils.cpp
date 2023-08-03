

#include "utils.h"


vector<vector<string>> PrintTree::printTree(TreeNode* root) {
    // Initialize
    this->height = getHeight(root);
    int col_num = pow(2,this->height + 1) - 1;
    for(int i = 0; i < this->height + 1; i++){
        vector<string> empty_row(col_num,"");
        this->res.push_back(empty_row);
    }

    // Fill in fields
    _printTree(root, 0, col_num / 2);
    print_2dvec(res);
    return this->res;
}

void PrintTree::_printTree(TreeNode* root, int row, int col) {

    if(!root)
        return;

    res[row][col] = to_string(root->val);

    int offset = pow(2, this->height - row - 1);
    _printTree(root->left, row + 1, col - offset);
    _printTree(root->right, row + 1, col + offset);
};

// root is at height 0
int PrintTree::getHeight(TreeNode* root) {
    if(!root)
        return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}




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




