//从大到小合并，为式直接建立了一个新的链表，代码有点臭上。。。
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head  = new ListNode(0);
        ListNode *p = head;
        int flag1 = 0, flag2 = 0;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                head->next = new ListNode(l1->val);
                head = head->next;
                if(l1->next!=NULL)
                    l1 = l1->next;
                else
                {
                    flag1 = 1;
                }
            }
            else if(l1->val > l2->val)
            {
                head->next = new ListNode(l2->val);
                head = head->next;
                if(l2->next != NULL)
                    l2 = l2->next;
                else
                {
                    flag2 = 1;
                }
            }
            else
            {
                head->next = new ListNode(l2->val);
                head = head->next;
                head->next = new ListNode(l2->val);
                head = head->next;
                if(l1->next!=NULL)
                    l1 = l1->next;
                else
                {
                    flag1 = 1;
                }
                if(l2->next != NULL)
                    l2 = l2->next;
                else
                {
                    flag2 = 1;
                }
            }
            if(flag1 || flag2) break;
        }
        while(l1 != NULL && !flag1)
        {
            head->next = new ListNode(l1->val);
            head = head->next;
            if(l1->next!=NULL)
                l1 = l1->next;
            else break;
        }
        while(l2 != NULL && !flag2)
        {
            head->next = new ListNode(l2->val);
            head = head->next;
            if(l2->next != NULL)
                l2 = l2->next;
            else break;
        }
        return p->next;
    }
};
