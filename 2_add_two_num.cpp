


#include <iostream>
#include <vector>  
using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void print_list(ListNode* node);

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* result = new ListNode;
        ListNode* cur_node = result;
        ListNode* zero_node = new ListNode(0,nullptr);
        int carry = 0;

        result->val = (l1->val + l2->val) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        while (l1->next || l2->next || carry)
        {
            ListNode* next_node = new ListNode;
            
            if(nullptr == (l1 = l1->next))
                l1 = zero_node;
            if(nullptr == (l2 = l2->next))
                l2 = zero_node;

            next_node->val = (l1->val + l2->val) % 10 + carry ;
            carry = (l1->val + l2->val + carry) / 10;
            if(next_node->val >= 10)
            {
                next_node->val %= 10;
                carry = 1;
            }
            cur_node->next = next_node;
            cur_node = next_node;
            
        }

        return result;
    }
};

void print_list(ListNode* node)
{
    while(node)
    {
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;
}


int main()
{

    // 2->4->3
    // 5->6->4
    ListNode l1_node3(3);
    ListNode l1_node2(4,&l1_node3);
    ListNode l1_node1(2,&l1_node2);
    ListNode l2_node3(4);
    ListNode l2_node2(6,&l2_node3);
    ListNode l2_node1(5,&l2_node2);

    print_list(&l1_node1);
    print_list(&l2_node1);
    ListNode* result = Solution().addTwoNumbers(&l1_node1, &l2_node1);

    print_list(result);

    
}
