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
    ListNode* reverseList(ListNode* head) {
        ListNode* curptr = NULL;
        ListNode* nextptr = head;
        while(nextptr!=NULL)
        {
            ListNode* tmpptr = nextptr->next;
            nextptr->next=curptr;
            curptr = nextptr;
            nextptr = tmpptr;
        }
        return curptr;

    }
};