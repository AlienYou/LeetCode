class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        queue<TreeNode*> que;
        que.push(root);
        string data;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node) {
                    data += to_string(node->val) + ",";
                    que.push(node->left);
                    que.push(node->right);
                } else 
                    data += "*,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return nullptr;
        stringstream ss(data);
        vector<TreeNode*> vec;
        while (getline(ss, data, ',')) {
            if (data != "*") {
                vec.push_back(new TreeNode(atoi(data.c_str())));
            } else 
                vec.push_back(nullptr);
        }
        queue<TreeNode*> que;
        TreeNode* root = vec[0];
        que.push(vec[0]);
        int index = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                node->left = vec[index++];
                node->right = vec[index++];
                if (node->left != nullptr)
                    que.push(node->left);
                if (node->right != nullptr)
                    que.push(node->right);
            }
        }
        return root;
    }
};