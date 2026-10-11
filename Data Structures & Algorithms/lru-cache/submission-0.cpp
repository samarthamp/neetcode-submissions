struct Node 
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), key(0), next(nullptr), prev(nullptr) {}
    Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
};

void print_vector(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";
}

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    int MAX_SIZE;
    Node* left = new Node();
    Node* right = new Node();

public:
    LRUCache(int capacity) {
        MAX_SIZE = capacity;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) 
        {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) remove(mp[key]);
        
        Node* new_node = new Node(key, value);
        mp[key] = new_node;
        insert(new_node);

        if (mp.size() > MAX_SIZE)
        {
            auto lru = left->next;
            int temp = mp.erase(lru->key);
            remove(lru);
        }
    }

    // remove the node from the list
    void remove(Node* node)
    {
        auto prev = node->prev;
        auto next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // insert the node at the right
    void insert(Node* node)
    {
        auto prev = right->prev;
        auto next = right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }
};
