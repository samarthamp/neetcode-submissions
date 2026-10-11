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
        if ((!head->next) || (!head->next->next)) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_part = slow->next;
        ListNode* right_ptr = reverseList(second_part);
        slow->next = nullptr;
        second_part->next = nullptr;

        ListNode* left_ptr = head;

        while (right_ptr)
        {
            auto templeft = left_ptr->next;
            auto tempright = right_ptr->next;

            left_ptr->next = right_ptr;
            right_ptr->next = templeft;

            left_ptr = templeft;
            right_ptr = tempright;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        else if (!head->next) return head;
        else
        {
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while (curr)
            {
                auto temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            return prev;
        }
    }
};
