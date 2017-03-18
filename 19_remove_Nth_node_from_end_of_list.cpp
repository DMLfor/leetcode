//倒数变正数,然后删除
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *last, *Next, *p;
        p = head;
        int m = 1;
        while(p->next!=NULL)
        {
            m++;
            p=p->next;
        }
        n = m - n+1;
        int cnt = 1;
        if(n == 1) { head = head->next; return head;}
        p = head;
        while(p != NULL)
        {
            last = p;
            p = p->next;
            cnt++;
            if(cnt == n){
                last->next = p->next;
                break;
            }
        }
        return head;
    }
};
