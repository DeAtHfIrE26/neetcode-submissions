class LRUCache {
    struct Node{
        int k, v;
        Node *prev = nullptr, *next = nullptr;
        Node(int k = 0, int v = 0) : k(k), v(v){}
    };
    int  cap;
    Node *head, *tail;
    unordered_map<int, Node*>mp;

    void unlink(Node* n){ n->prev->next = n -> next; n -> next -> prev = n -> prev;}
    void pushfront(Node* n){
        n -> next = head -> next; n -> prev = head;
        head -> next -> prev = n; head -> next = n;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(); tail = new Node();
        head -> next = tail; tail -> prev = head;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        unlink(it -> second); pushfront(it -> second);
        return it -> second -> v;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()){
            it -> second -> v = value;
            unlink(it->second); pushfront(it->second);
            return;
        }
        if((int)mp.size() == cap){
            Node* lru = tail -> prev;
            unlink(lru); mp.erase(lru->k); delete lru;
        }
        Node* n = new Node(key, value);
        pushfront(n); mp[key] = n;
    }
};
