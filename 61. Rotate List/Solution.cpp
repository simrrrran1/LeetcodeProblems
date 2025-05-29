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
        // Edge case: if the list is empty, has one node, or k is 0, return as is
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        int len = 1;
        ListNode* temp = head;
        while (temp->next) {
            len++;
            temp = temp->next;
        }

        // Step 2: Connect the last node to the head to make it circular
        temp->next = head;

        // Step 3: Normalize k in case it's greater than list length
        k %= len;

        // Step 4: Find the node just before the new head after rotation
        // To rotate right by k, new head is at (len - k)th position
        k = len - k;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }

        // Step 5: Break the circular link and set new head
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
