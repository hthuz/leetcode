

#include <iostream>
#include "lib.h"
using namespace std;


class Solution {
public:
    // Go through the list and see if a node is traversed twice
    // Time complexity: O(n^2)
    bool hasCycle(ListNode *head){
        vector<ListNode*> listvec = {};
        ListNode* node;

        node = head;
        while(node)
        {
            if(in_listvec(listvec,node))
                return true;
            listvec.push_back(node);
            node = node->next;
        }

        return false;
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
    bool result;

    head = arr_to_list(arr,4);

    result = Solution().hasCycle(head);
    cout << result << endl;


}

