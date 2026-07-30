class Node
{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node)
    {
        Node* previous = node->prev;
        Node* nextNode = node->next;

        previous->next = nextNode;
        nextNode->prev = previous;
    }

    void insert(Node* node)
    {
        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
        {
            return -1;
        }

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        if(mp.size() == capacity)
        {
            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insert(node);
        mp[key] = node;
    }
};