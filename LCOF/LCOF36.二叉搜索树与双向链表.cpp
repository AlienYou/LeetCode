class Solution {
public:
    Node* treeToDoublyList1(Node* root) {
        if (root == nullptr)
            return nullptr;
        stack<Node*> st;
        Node dummy(0);
        Node* pre = &dummy;
        Node* node = root;
        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                pre->right = node;
                node->left = pre;
                pre = node;
                node = node->right;
            }
        }
        pre->right = dummy.right;
        dummy.right->left = pre;
        return dummy.right;
    }
    Node* pre = nullptr;
    Node* head = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void dfs(Node* node) {
        if (node == nullptr) return;
        dfs(node->left);
        if (pre) pre->right = node; 
        else head = node;
        node->left = pre;
        pre = node;
        dfs(node->right);
    }
};