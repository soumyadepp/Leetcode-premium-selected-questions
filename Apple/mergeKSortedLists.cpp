/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res;
        ListNode *ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(ListNode* head : lists)
        {
            while(head!=NULL)
            {
                pq.push(head->val);
                head = head->next;
            }
        }
        res = new ListNode();
        ans = res;
        while(pq.size())
        {
            res->next = new ListNode(pq.top());
            res = res->next;
            pq.pop();
        }
        return ans->next;
    }
};
