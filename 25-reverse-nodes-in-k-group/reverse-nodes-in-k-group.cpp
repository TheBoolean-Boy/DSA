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
    void reverse(ListNode* head ){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp !=  nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
       
    }
    ListNode* getKthNode(ListNode* head, int k){
        ListNode* temp = head;
        k -= 1;
        while(temp != nullptr && k >0 ){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp != nullptr){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == nullptr){
                if(prevNode)prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode -> next;
            kthNode->next = nullptr;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
            
        }
        return head;
    }
};