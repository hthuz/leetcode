
#include "lib.h"
#include "iostream"

class Solution {
public:
    // Go through the list and see if a node is traversed twice
    // Time complexity: O(n^2)
    ListNode* detectCycle(ListNode *head){
        vector<ListNode*> listvec = {};
        ListNode* node;

        node = head;
        while(node)
        {
            if(in_listvec(listvec,node))
                return node;
            listvec.push_back(node);
            node = node->next;
        }

        return nullptr;
    }
private:
    bool in_listvec(vector<ListNode*>& listvec, ListNode* node){
        for(ListNode* x : listvec)
            if (x == node)
                return true;
        return false;

    }
};


int main()
{
   int arr[4] = {3,2,0,-4};
   ListNode* head;
   ListNode* node1;
   ListNode* node2;
   ListNode* result;

   head = arr_to_list(arr,4);
   node1 = get_list_node( head, 1);
   node2 = get_list_node(head, 3);
   node2->next = node1;
   
   result = Solution().detectCycle(head);
   cout << result->val << endl;
}


