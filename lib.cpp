
#include <iostream>
#include "lib.h"

using namespace std;


void print_vec(vector<int>& nums)
{
    cout << "[";
    for(int x : nums)
        cout << x << " ";
    cout << "]" << endl;
}


void print_2dvec(vector<vector<int>>& nums)
{
    cout << "[";
    for(vector<int> one_vec : nums)    
    {
        cout << "[";
        for(int x : one_vec)
            cout << x << " ";
        cout << "]";
    }
    cout << "]" << endl;
}

ListNode* get_list_node(ListNode* head, int index)
{
    ListNode* node = head;
    while(index)
    {
        node = node->next;
        index--;
    }
    return node;
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
