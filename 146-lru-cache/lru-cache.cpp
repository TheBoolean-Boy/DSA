class LRUCache {
public:
    class Node{

        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        public:
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map< int, Node*>mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head ->next = tail;
        tail ->prev = head;
    }

    void addNode(Node* newNode){
        Node* temp = head ->next;
        newNode ->next = temp;
        newNode ->prev = head;
        head ->next = newNode;
        temp ->prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* delNext = delNode->next;
        Node* delPrev = delNode->prev;
        delNext ->prev = delPrev;
        delPrev ->next = delNext;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return resNode ->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == cap){
            Node* delNode = tail->prev;
            mp.erase(tail->prev->key);
            deleteNode(delNode);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */