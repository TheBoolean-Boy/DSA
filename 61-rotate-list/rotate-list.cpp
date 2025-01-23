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
        if(head == nullptr)return head;
        int len  = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            len++;
        }
        k = k % len;
        if(k == 0)return head;
        temp->next = head;
        ListNode* newTail = head;
        for(int i = 1 ; i < (len - k); i++){
            newTail = newTail ->next;
        }
        cout << newTail->val << " newtail value ";
        ListNode* newhead = newTail ->next;
        newTail->next = nullptr;

        return newhead;

    }
};