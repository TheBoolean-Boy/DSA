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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* front;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        int cnt = 0;
       
        while(temp != nullptr && cnt < k){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            cnt++;
        }
        int count = 0;
        
        while(temp != nullptr){
            temp = temp->next;
            count++;
            if(count ==k )break;
            
        }
        
        if(count >= k){
            if(front != nullptr){
                head->next = reverseKGroup(front, k);
            }
        }
        else{
            head->next = front;
        }
        return prev;
    }
};