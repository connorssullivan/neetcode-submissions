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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) 
            return list2;
        if (!list2)
            return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* newHead = (curr1->val < curr2->val) ? curr1 : curr2;
        ListNode* tail = newHead;

        (curr1->val < curr2->val) ? curr1 = curr1->next : curr2 = curr2->next;
        

        while (curr1 && curr2)
        {
            ListNode* nextNode = (curr1->val < curr2->val) ?  curr1 : curr2;
            (curr1->val < curr2->val) ? curr1 = curr1->next : curr2 = curr2->next;

            tail->next = nextNode;
            tail = tail->next;
        }

        if (curr1)
            tail->next = curr1;
        if (curr2)
            tail->next = curr2;

        return newHead;
    }
};
