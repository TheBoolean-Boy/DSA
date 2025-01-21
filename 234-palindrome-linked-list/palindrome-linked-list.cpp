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
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr )return false;
        if(head->next == nullptr)return true;
       ListNode* slow = head;
       ListNode* fast = head;
       while( fast->next != nullptr  && fast->next->next != nullptr){
        slow = slow->next;
        fast= fast->next->next;
       } 
       ListNode* newHead = reverse(slow->next);
       ListNode* temp = head;
       while(temp != nullptr && newHead != nullptr){
        if(newHead->val != temp->val){
            return false;
        }
        newHead = newHead->next;
        temp = temp->next;
       }
       newHead = reverse(newHead);
       return true;
    }
};