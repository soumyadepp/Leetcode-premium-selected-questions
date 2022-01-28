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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next){
            return head;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp -> next){
            temp = temp -> next;
            cnt++;
        }
        cnt++;
        k = k % cnt;
        temp -> next = head;
        int c = 0;
        while(temp && c < cnt - k){
            temp = temp -> next;
            c++;
        }
        head = temp -> next;
        temp -> next = NULL;
        return head;
    }
};
