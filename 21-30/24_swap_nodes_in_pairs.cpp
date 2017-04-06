//记录前一个点的地址，和前两个点位置，到偶数个节点的时候交换(z指针真的是容易迷糊
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmp = NULL, *last = NULL, *p = head,*lastTwo = NULL;
        ListNode *ans = new ListNode(0);
        ans->next = head;
        int cnt = 0;
        while(p != NULL)
        {
            cnt++;
            if(cnt % 2 == 0 && cnt > 0)
            {
                tmp = last;
                last->next = p->next;
                p->next = tmp;
                if(lastTwo == NULL)
                    ans->next = p, lastTwo = last;
                if(cnt>2)lastTwo->next= p, lastTwo = last;
                p = last;
            }
            last = p;
            p = p->next;

        }
        return ans->next;
    }
};
