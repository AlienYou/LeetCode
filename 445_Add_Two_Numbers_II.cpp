ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<ListNode*> st1;
	stack<ListNode*> st2;
	ListNode* head = l1;
	while (head)
	{
		st1.push(head);
		head = head->next;
	}
	head = l2;
	while (head)
	{
		st2.push(head);
		head = head->next;
	}
	if (st1.size() < st2.size())
	{
		swap(st1, st2);
	}
	int carry = 0;
	ListNode* pRes = nullptr;
	while (st1.size())
	{
		int val = 0;
		if (st2.size() > 0)
		{
			ListNode* pNode = st2.top();
			val = pNode->val;
			st2.pop();
		}
		ListNode* pNode = st1.top();
		st1.pop();
		val = val + pNode->val + carry;
		pNode->val = val % 10;
		pRes = pNode;
		carry = val / 10;
	}
	if (carry == 1)
	{
		ListNode* pHead = pRes;
		pRes = new ListNode(1);
		pRes->next = pHead;
	}
	return pRes;
}