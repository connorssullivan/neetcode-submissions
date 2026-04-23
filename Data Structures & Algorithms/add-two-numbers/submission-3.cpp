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
        
        int carry {};
        ListNode* head = nullptr;
        ListNode* curr = head;

        while (l1 || l2)
        {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;

            int sum = a + b + carry;

            ListNode* new_node = new ListNode();

            if (sum <= 9)
            {
                new_node->val = sum;
                carry = 0;
            }

            else
            {
                new_node->val = sum - 10;
                carry = 1;
            }

            if (!head)
            {
                head = new_node;
            }

            else
            {
                curr->next = new_node;
            }

            curr = new_node;
            if (l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if (carry != 0)
        {
            curr->next = new ListNode(carry);
        }

        return head;
    }
};
