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
        if(!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        ListNode* tail = head;
        k %= len;

        for(int i=0; i<len-k-1; i++){
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;



    }
};