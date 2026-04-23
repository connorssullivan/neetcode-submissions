/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* curr_l1 = l1;
        ListNode* curr_l2 = l2;

        ListNode dummy {0, nullptr};
        ListNode* curr = new ListNode( (curr_l1->val + curr_l2->val)%10,  nullptr);
        int remainder = (curr_l1->val + curr_l2->val) / 10;
        dummy.next = curr;
        curr_l1 = curr_l1->next;
        curr_l2 = curr_l2->next;

        while (curr_l1 || curr_l2 || remainder > 0)
        {
            int total = 0;
            if (curr_l1)
            {
                total += curr_l1->val;
                curr_l1 = curr_l1->next;
            }
            if (curr_l2)
            {
                total += curr_l2->val;
                curr_l2 = curr_l2->next;
            }
            if (remainder > 0)
                total += remainder;
            
            curr->next = new ListNode(total%10,  nullptr);
            remainder = (total) / 10;
            curr = curr->next;
        }

        

        return dummy.next;

    }
};
