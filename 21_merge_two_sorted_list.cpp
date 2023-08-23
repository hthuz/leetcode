
#include "utils.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;

        while(cur1 || cur2)
        {
            ListNode* smaller_node;
            if(cur1 && (!cur2 || cur1->val <= cur2->val)) {
                smaller_node = cur1;
                cur1 = cur1->next;
            } else{
                smaller_node = cur2;
                cur2 = cur2->next;
            }
            cur->next = new ListNode(smaller_node->val);
            cur = cur->next;
            smaller_node = smaller_node->next;
        }
        cur = dummy->next;
        free(dummy);
        return cur;
    }
};

int main()
{
    int arr1[] = {};
    int arr2[] = {2,3,4,5};
    ListNode* list1 = arr_to_list(arr1, 0);
    ListNode* list2 = arr_to_list(arr2, 4);
    ListNode* ans = Solution().mergeTwoLists(list1, list2);
    print_list(ans);
}
