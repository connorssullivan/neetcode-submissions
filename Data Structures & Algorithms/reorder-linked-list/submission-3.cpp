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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        vector<ListNode*> nodes;

        ListNode* curr = head;

        while (curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int n = nodes.size();


        int right = n-1;
        int left = 0;

        while (right > left)
        {
            nodes[left]->next = nodes[right];
            left++;

            if (left == right)
                break;
            
            nodes[right]->next = nodes[left];
            right--;
        }

        nodes[left]->next = nullptr;

    }
};
