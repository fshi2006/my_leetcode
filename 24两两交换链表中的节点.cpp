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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newNode=new ListNode();
        ListNode* prev=newNode;
        prev->next=head;
        while(head!=NULL&&head->next!=NULL){
            prev->next=head->next;
            prev=prev->next;
            head->next=prev->next;
            prev->next=head;
            head=head->next;
            prev=prev->next;
        }
        return newNode->next;
    }
};