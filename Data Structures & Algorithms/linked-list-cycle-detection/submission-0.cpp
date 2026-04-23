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
    bool hasCycle(ListNode* head) {
        if (!head)
            return true;
        ListNode* tail = head->next;

        while (tail)
        {
            if (tail == nullptr)
                break;
            if (tail == head)
                return true;
            
            tail = tail->next;
            if (tail == nullptr)
                break;
            tail = tail->next;

            head = head->next;

        }

        return false;
    }
};
