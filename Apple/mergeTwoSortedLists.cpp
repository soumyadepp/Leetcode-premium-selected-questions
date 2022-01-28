/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
        {
            return NULL;
        }
        if(l1 && !l2)
        {
            return l1;
        }
        if(!l1 && l2)
        {
            return l2;
        }
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *temp3 = new ListNode(min(temp1->val,temp2->val));
        ListNode *retHead = temp3;
        if(temp1->val > temp2->val)
        {
            temp2 = temp2->next;
        }
        else
            temp1 = temp1->next;
        while(temp1 && temp2)
        {
            if(temp1->val < temp2->val)
            {
                ListNode *inserter = new ListNode(temp1->val);
                temp3->next = inserter;
                temp3 = temp3->next;
                temp1 = temp1 -> next;
            }
            else
            {
                ListNode *inserter = new ListNode(temp2->val);
                temp3->next = inserter;
                temp3 = temp3 -> next;
                temp2 = temp2 -> next;
            }
        }
        while(temp1)
        {
            ListNode *inserter = new ListNode(temp1->val);
            temp1 = temp1 -> next;
            temp3->next = inserter;
            temp3 = temp3 -> next;
        }
        while(temp2)
        {
            ListNode *inserter = new ListNode(temp2->val);
            temp2 = temp2 ->next;
            temp3 -> next = inserter;
            temp3 = temp3 -> next;
        }
        return retHead;
    }
};
