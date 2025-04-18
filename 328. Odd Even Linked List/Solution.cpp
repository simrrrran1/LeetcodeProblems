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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead = new ListNode(0);
        ListNode* oddHead = new ListNode(0);

        ListNode* eTemp = evenHead;
        ListNode* oTemp = oddHead;
        ListNode* temp = head;
        int i = 0;

        while(temp){
            if(i % 2 == 1){
                eTemp->next = temp;
                eTemp = eTemp->next;
            }else{
                oTemp->next = temp;
                oTemp = oTemp->next;
            }
            i++;
            temp = temp->next;
        }
        eTemp->next = NULL;
        oTemp->next = evenHead->next;
        return oddHead->next;
    }
};