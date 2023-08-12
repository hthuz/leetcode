

#include"utils.h"


// It's selection sort. I misunderstood

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev;
        ListNode* cur;
        ListNode* max_node;
        ListNode* max_node_prev;
        ListNode* sorted_head = nullptr;

        while(dummy->next) 
        {
            prev = dummy;
            cur = dummy->next;
            max_node = cur;
            max_node_prev = prev;
            // Find node with maximal val
            while(cur) 
            {
                // cout << cur->val << " ";
                if(cur->val > max_node->val)
                {
                    max_node = cur;
                    max_node_prev = prev;
                }
                prev = cur;
                cur = cur->next;
            }
            // Delete node with maximal val
            max_node_prev->next = max_node->next;
            // Append maximal node to sorted list.
            max_node->next = sorted_head;
            sorted_head = max_node;
        }
        // free(dummy);
        return sorted_head;

    }
};

int main()
{
    int arr[] = {-1,5,3,4,0};
    ListNode* head = arr_to_list(arr,5);
    print_list(head);
    head = Solution().insertionSortList(head);
    print_list(head);

}
