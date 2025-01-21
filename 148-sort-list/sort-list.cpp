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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1 ->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2-> next;
            }
        }
        if(list1)temp->next = list1;
        else if(list2) temp->next = list2;
        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};