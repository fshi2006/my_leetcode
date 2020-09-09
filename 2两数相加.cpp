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
        int len1=1,len2=1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while(p1->next != NULL)
            {
                p1 = p1->next;
                len1++;
            }
        while(p2->next != NULL)
            {
                p2 = p2->next;
                len2++;
            }
        if(len1>len2)
            {
                for(int i = 0;i<len1-len2;i++)
                {
                    p2->next = new ListNode(0);
                    p2 = p2->next;
                }
                
            }
        else
            {
                for(int i = 0;i<len2-len1;i++)
                {
                    p1->next = new ListNode(0);
                    p1 = p1->next;
                }        
            }
        p1 = l1;p2 =l2;
        bool count=false;//记录进位
        ListNode* l3=new ListNode(0);//存放结果的链表
        ListNode* w=l3;//l3的移动指针
        int i=0;//记录相加结果
        while(p1!=NULL&&p2!=NULL)
        {
            i=count+p1->val+p2->val;
            w->next=new ListNode(i%10);
            count=i>=10?true:false;
            w=w->next;
            p1=p1->next;
            p2=p2->next;
        }
        if(count)//若最后还有进位
        {
            w->next=new ListNode(1);
            w=w->next;
        }
        return l3->next; 
    }

};