/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1 != p2) {
            if (!p2) return false;
            p1 = p1->next;
            p2 = p2->next;
            if (!p2) return false;
            p2 = p2->next;
        }
        return true;
    }
};