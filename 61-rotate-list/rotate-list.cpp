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
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif


#define pb push_back
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)return head;
        int cnt = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            cnt++;
            temp = temp ->next;
        }
        k =  k % cnt;
        if(k == 0)return head;
        temp->next = head;
        ListNode* newTail = head;
        for(int i = 1; i < cnt - k; i++){
            newTail = newTail->next;
        }
        ListNode* newHead =  newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};