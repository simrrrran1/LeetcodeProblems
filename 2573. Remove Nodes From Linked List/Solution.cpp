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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        curr = reverse(curr);

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = curr;

        while(curr){
            if(prev-> val > curr->val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return reverse(dummy->next);


        // stack<ListNode*> s;

        // while(temp){
        //     while(!s.empty() && s.top()->val < temp->val){
        //         s.pop();
        //     }
        //     s.push(temp);
        //     temp = temp->next;
        // }
        // cout<< s.top()->val << endl;

        
        // ListNode* newHead = NULL;
        

        // while(!s.empty()){
        //     temp = s.top();
        //     s.pop();
        //     temp->next = newHead;
        //     newHead = temp;
        // }

        // return temp;

    }
};