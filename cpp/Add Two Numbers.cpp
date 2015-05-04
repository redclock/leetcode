/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode node(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* parent =&node;
        int more = 0;
        
        while (p1 || p2 || more) {
            int d1 = p1 ? p1->val : 0;
            int d2 = p2 ? p2->val : 0;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
            more += d1 + d2;
            ListNode* node = new ListNode(more % 10);
            parent->next = node;
            parent = node;
            more /= 10;
        }
        
        return node.next;
    }
};