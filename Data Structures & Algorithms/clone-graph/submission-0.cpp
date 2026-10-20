class Solution {
private:
    unordered_map<Node*, Node*> cloned;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (cloned.count(node)) return cloned[node];

        Node* root = new Node(node->val);
        cloned[node] = root;

        int n = node->neighbors.size();

        for (int i = 0; i < n; i++)
        {
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
    }
};