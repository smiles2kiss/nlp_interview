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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        // 思路
		// 初始化root节点存放头节点，temp节点为空
		// 每次扫描到head的后一个节点temp，将temp插入到root之前，并更新root节点的值 
		// 自始自终head都停留在原始头节点的位置 
        ListNode* root = head;
        ListNode* temp = head;
        while (head->next) {
            temp = head->next;
            head->next = temp->next;
            temp->next = root;
            root = temp;
        }
        return root;
    }
};
