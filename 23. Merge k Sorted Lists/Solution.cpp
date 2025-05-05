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
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(a && b){
            if(a->val < b->val){
                temp->next = a;
                a = a->next;
            }else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(a){
            temp->next = a;
        }
        if(b){
            temp->next = b;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* head = merge(lists[0], lists[1]);
        for(int i=2; i<lists.size(); i++){
            head = merge(head, lists[i]);
        }
        return head;
    }
};