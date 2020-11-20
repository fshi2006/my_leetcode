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
        ListNode* fisrtnode = new ListNode(0);
        ListNode* cur = fisrtnode ;
        cur->next = head;
        while(cur->next!= NULL)
        {
            if(cur->next->val==val)
            {
                auto tmp_cur = cur->next;
                cur->next = cur->next->next;
                delete tmp_cur;
            }
            else
                cur = cur->next;
        } 
        return fisrtnode->next;   
    }
};