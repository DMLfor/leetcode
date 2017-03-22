//比较复杂，每k个节点后让这k个节点的指向反向，注意变指向的时候的指针指向。。
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1)return head;
        ListNode *fir = new ListNode(0), *ans =new ListNode(0);
        ListNode *p = head;
        fir->next = head;
        ans = fir;
        int cnt = 0;
        while(p != NULL)
        {
            cnt++;
            if(cnt == k)
            {
                cnt = 0;
                ListNode *tmp1 = fir->next, *tmp2 = fir->next->next;
                ListNode *cur = tmp1, *nxt = tmp2;
                while(cur != p)
                {
                    ListNode *tmp = nxt->next;
                    nxt->next = cur;
                    cur = nxt;
                    nxt = tmp;
                }

                fir->next = p;
                p = nxt;
                tmp1->next = nxt;
                fir = tmp1;
            }
            else p = p->next;
        }
        return ans->next;
    }
};
