

class compare
{
public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next != NULL)
            {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};