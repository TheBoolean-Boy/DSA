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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr && n == 1)return nullptr;
        ListNode* fast = head;
        for(int i =0; i<n ; i++){
            fast = fast->next;
        }
        if(fast == nullptr ){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};