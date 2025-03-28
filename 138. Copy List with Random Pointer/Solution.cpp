/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        // create new list 

        Node* temp = head;

        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode; 
            temp = newNode->next;
        }

        // create random vaale links

        temp = head;

        while(temp){
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        // get new list

        Node* newHead = head->next;
        temp = head->next;

        while(temp){
            head->next = temp->next;
            head = head->next;
            if(!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        return newHead;
    }
};