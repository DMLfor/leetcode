/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//模拟左对齐加法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p, *ans;
        ans = new ListNode(0);
        p = ans;
        int c = 0;
        while(l1  != NULL || l2 != NULL)
        {
            int a = (l1 == NULL ? 0 : l1->val);
            int b = (l2 == NULL ? 0 : l2->val);
            c = c + a + b;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            ans->next = new ListNode(c%10);
            c = c/10;
            ans = ans->next;
        }
        if(c)
            ans->next = new ListNode(c);
        return p->next;
    }
};
