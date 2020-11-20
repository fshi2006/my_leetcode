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
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode *>  list_address;
        while(head!=nullptr)
        {
            if(findNode(list_address,head))
            {
                return head;
            }
            list_address.push_back(head);
            head = head->next;
        }
        return nullptr;
    }

      bool findNode(vector<ListNode *>  &list_address, ListNode *node) {
        for (ListNode *n:list_address) {
            if (n==node) {
                return true;
            }
        }
        return false;
    }
};

