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
        
        ListNode* tortise = head;
        ListNode* hare = head;

        // Find middle point
        while (hare && hare->next)
        {
            tortise = tortise->next;
            hare = hare->next->next;
        }

        // Reverse second half
        ListNode* curr = tortise->next;
         tortise->next = nullptr; 
        ListNode* prev = nullptr;
        ListNode* head2 = tortise->next;

        while (curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head2 = prev;


        // Now Just put them in right order
        ListNode* start = head;
        ListNode* start_reverse = head2;

        while (start_reverse)
        {
            ListNode* temp1 = start->next;
            ListNode* temp2 = start_reverse->next;

            start->next = start_reverse;
            start_reverse->next = temp1;

            start = temp1;
            start_reverse = temp2;
            
            
        }

        


    }
};
