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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* newHead = dummyNode;
        while(t1 && t2){
            if(t1 -> val < t2 -> val){
                dummyNode -> next = new ListNode(t1 -> val);
                t1 = t1 -> next;
            }
            else{
                dummyNode -> next = new ListNode(t2 -> val);
                t2 = t2 -> next;
            }
            dummyNode = dummyNode -> next;
        }
        while(t1){
            dummyNode -> next = new ListNode(t1 -> val);
            t1 = t1 -> next;
            dummyNode = dummyNode -> next;
        }
        while(t2){
            dummyNode -> next = new ListNode(t2 -> val);
            t2 = t2 -> next;
            dummyNode = dummyNode -> next;
        }
        return newHead -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        ListNode* prev = nullptr;
        while(fastPointer != NULL && fastPointer -> next != NULL){
            prev = slowPointer;
            slowPointer = slowPointer -> next;
            fastPointer = fastPointer -> next -> next;
        }
        prev -> next = NULL;
        //merge sort here
        ListNode* start1 = sortList(head);
        ListNode* start2 = sortList(slowPointer);
        
        return merge(start1,start2);
    }
};
