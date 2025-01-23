/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNodesinBetween(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while( temp != nullptr){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* getTheDeepCopy(Node* head){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;
        while(temp != nullptr){
            res -> next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }
        return dummyNode -> next;
    }
    Node* copyRandomList(Node* head) {
        insertNodesinBetween(head);
        connectRandomPointers(head);
        return getTheDeepCopy(head);
    }
};