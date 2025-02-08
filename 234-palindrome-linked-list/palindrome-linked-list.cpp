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
ListNode* reverseList(ListNode* head){
    if(head == nullptr || head -> next == nullptr)return head;
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while(temp != nullptr){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)return false;
        if(head -> next == nullptr)return true;

        ListNode* fast = head->next->next;
        ListNode* slow  = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* secondaryHead = reverseList(slow -> next);
        ListNode* temp = head;
        while(secondaryHead != nullptr && temp != nullptr){
            if(secondaryHead -> val != temp -> val){
                return false;
            }
            secondaryHead = secondaryHead->next;
            temp = temp -> next;
        }
        secondaryHead = reverseList(secondaryHead);
        return true;
    }
};