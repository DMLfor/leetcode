//优先队列
struct ListNodecmp

{
    bool operator()(const ListNode*p, const ListNode*q)
    {
        return p->val > q->val;
    }
};
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
         priority_queue<ListNode*, vector<ListNode*>, ListNodecmp> list_queue;
         for(int i = 0; i<lists.size(); i++)
         {
         p = head;
         while(!list_queue.empty())
         {
             tmp = list_queue.top();
             list_queue.pop();
             p->next = tmp;
             p = p->next;
             if(tmp->next)
                list_queue.push(tmp->next);
         }
         return head->next;
    }
};
