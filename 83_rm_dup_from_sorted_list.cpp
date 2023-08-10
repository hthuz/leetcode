

#include "utils.h"


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val) {
                ListNode* old_next = cur->next;
                cur->next = old_next->next;
                // free(old_next);
                continue;
            }
            cur = cur->next;
        }
        return head;
    }
};


int main() 
{
    int arr[] = {1,1,1,2};
    ListNode* head = arr_to_list(arr, 4);
    print_list(head);
    ListNode* new_head = Solution().deleteDuplicates(head);
    print_list(new_head);

}
