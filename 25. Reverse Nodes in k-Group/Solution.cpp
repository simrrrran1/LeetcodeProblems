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
    ListNode* getKth(ListNode* head, int k){
        while(head && k>0){
            head = head->next;
            k--;
        } 
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        
        while(true){
            ListNode* kth = getKth(temp, k);
            if(!kth) break;
            ListNode* tempNext = kth->next;

            ListNode* prev = kth->next;
            ListNode* curr = temp->next;
            ListNode* tmp = curr;
        
            while(curr != tempNext){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            tmp = temp->next;
            temp->next = kth;
            temp = tmp;
        }

        return dummy->next;

    }
};