

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

vector<vector<int>> init_2dvec(int m, int n, int init_val)
{
    vector<vector<int>> f(m, vector<int>(n,init_val));
    // the address of vector doesn't change.
    // It seems that it's initialized into heap instead of local stack.
    return f;

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

template<typename T>
void print_2dvec(vector<vector<T>>& nums)
{
    for(vector<T> one_vec : nums)    
    {
        cout << "[";
        for(T x : one_vec)
        if (x == "")
            cout << " " << ",";
        else
            cout << x << ",";
        cout << "]\n";
    }
}

void print_2dvec(vector<vector<int>>& nums)
{
    for(vector<int> one_vec : nums)    
    {
        cout << "[";
        for(int x : one_vec)
            cout << x << ",";
        cout << "]\n";
    }
}

void print_2dvec(vector<vector<char>>& nums)
{
    for(vector<char> one_vec : nums)    
    {
        cout << "[";
        for(int x : one_vec)
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


ListNode* arr_to_list(int* array, int size)
{
    ListNode* head;
    ListNode* cur;
    int i;
    
    cur = new ListNode(array[0]);
    head = cur;
    for(i = 1; i < size ; i++)
    {
        ListNode* next = new ListNode(array[i]);
        cur->next = next;
        cur = next;
    }
    return head;
}


void print_list(ListNode* head)
{
    ListNode* node;
    node = head;
    int i = 0;
    while(node && i < 20)
    {
        cout << node->val << " ";
        node = node->next;
        i++;
    }
    cout << endl;
}
