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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;

        ListNode* hare = head;
        ListNode* tortoise = head;

        for (int i {0}; i < n; i++)
        {
            // If out of range
            if (!hare)
                return head;
            hare = hare->next;
        }

        if (!hare) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }

        while (hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        if (tortoise->next)
        {
            ListNode* temp = tortoise->next->next;
            delete tortoise->next;
            tortoise->next = temp;
        }


        return head;


    }
};


