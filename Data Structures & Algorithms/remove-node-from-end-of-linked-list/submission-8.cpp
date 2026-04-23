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
        
        vector<ListNode*> nodes;
        ListNode* curr = head;

        int size = 0;

        while (curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        if (n > nodes.size())
            return head;

        int index = nodes.size() - n;

        if (index == 0)
            return head->next;
        
        if (index + 1 < nodes.size())
            nodes[index - 1]->next = nodes[index + 1];
        else
            nodes[index - 1]->next = nullptr;

        delete nodes[index];

        return head;

    }
};
