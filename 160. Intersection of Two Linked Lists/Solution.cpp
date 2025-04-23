/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return NULL;
        //if(!headA) return headB;
        //if(!headB) return headA;
        
        //int lA = 0, lB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){
            tempA = tempA ? tempA->next : headB;
            tempB = tempB ? tempB->next : headA;
        }

        return tempA;

        // while(tempA){
        //     lA++;
        //     tempA = tempA->next;
        // }

        // while(tempB){
        //     lB++;
        //     tempB = tempB->next;
        // }

        // tempA = headA;
        // tempB = headB;

        
        // if(lB > lA){
        //     for(int i=0; i < lB-lA; i++){
        //         tempB = tempB->next;
        //     }
        // }else{
        //     for(int i=0; i < lA-lB; i++){
        //         tempA = tempA->next;
        //     }
        // }
        // while(tempA || tempB){
        //     if(tempA == tempB){
        //         break;
        //     }
        //     tempA = tempA->next;
        //     tempB = tempB->next;
        // }

        // return tempA;

    }
};