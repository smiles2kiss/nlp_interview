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
        if(headA == NULL)
            return NULL;
        if (headB == NULL)
            return NULL;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int countA = 0;
        int countB = 0;
        while(tempA) {
            countA = countA + 1;
            tempA = tempA->next;
        }
        while(tempB) {
            countB = countB + 1;
            tempB = tempB->next;
        }
    
        tempA = headA;
        tempB = headB;
        if (countA > countB) {
            int dif = countA - countB;
            for(int i = 0; i < dif; i++) {
                tempA = tempA->next;
            }
        }
        if (countA < countB) {
            int dif = countB - countA;
            for (int i = 0; i < dif; i++) {
                tempB = tempB->next;
            }
        }
        while(tempA && tempB) {
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;

    }
};
