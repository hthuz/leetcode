

#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void print_vec(vector<int> nums);

void print_2dvec(vector<vector<int>>& nums);

// Given a singly linked list, get the ith node of the list
ListNode* get_list_node(ListNode* head, int index);

// Given an array, transform it to a singly linked list
ListNode* arr_to_list(int* array, int size);

// Given a singly linked list, print all its values
void print_list(ListNode* head);


