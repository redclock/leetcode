/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* pre = NULL;
        while (p) {
            ListNode* q = p->next;
            if (p->val == val) {
                if (pre) 
                    pre->next = q;
                else
                    head = q;
            }
            else{
                pre = p;
            }
            p = q;
        }
        return head;
    }
};