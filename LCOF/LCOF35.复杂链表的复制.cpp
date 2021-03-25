class Solution {
public:
    Node* copyRandomList1(Node* head) {
        unordered_map<Node*, Node*> randomMap;
        Node dummy(0);
        Node* newNode = &dummy;
        Node* node = head;
        while (node) {
            if (randomMap.count(node)) {
                newNode->next = randomMap[node];
            } else {
                newNode->next = new Node(node->val);
                randomMap[node] = newNode->next;
            }
            if (node->random) {
                if (randomMap.count(node->random)) {
                    newNode->next->random = randomMap[node->random];
                } else {
                    Node* random = newNode->next->random = new Node(node->random->val);
                    randomMap[node->random] = random;
                }
            }
            node = node->next;
            newNode = newNode->next;
        }
        return dummy.next;
    }
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* node = head;
        while (node) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
        node = head;
        while (node) {
            if (node->random != nullptr)
                node->next->random = node->random->next;
            node = node->next->next;
        }
        node = head;
        Node* newHead = head->next;
        Node* newNode = head->next;
        while (newNode->next) {
            node->next = newNode->next;
            newNode->next = node->next->next;
            node = node->next;
            newNode = newNode->next;
        }
        node->next = nullptr;
        return newHead;
    }
};