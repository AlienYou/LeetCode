ListNode* insertionSortList(ListNode* head) {
	if (!head)
		return nullptr;
	ListNode* sortedHead = head;
	head = head->next;
	sortedHead->next = nullptr;
	while (head)
	{
		ListNode* pNode = head;
		if (sortedHead->val <= head->val)
		{
			head = head->next;
			pNode->next = sortedHead;
			sortedHead = pNode;    
		}
		else
		{
			ListNode* sortedLast = sortedHead;
			ListNode* sortedCur = sortedHead;
			while (sortedCur != nullptr && sortedCur->val > pNode->val)
			{
				sortedLast = sortedCur;
				sortedCur = sortedCur->next;
			}
			head = head->next;
			pNode->next = sortedCur;
			sortedLast->next = pNode;    
		}
	}
	ListNode* reverseNode = nullptr;
	while (sortedHead) 
	{
		ListNode* pCur = sortedHead;
		sortedHead = sortedHead->next;
		pCur->next = reverseNode;
		reverseNode = pCur;
	}
	return reverseNode;
}

ListNode* insertionSortList(ListNode* head) {
	if (!head)
		return nullptr;
	ListNode* sortedHead = head;
	head = head->next;
	sortedHead->next = nullptr;
	while (head)
	{
		ListNode* pNode = head;
		if (sortedHead->val <= head->val)
		{
			head = head->next;
			pNode->next = sortedHead;
			sortedHead = pNode;    
		}
		else
		{
			ListNode* sortedLast = sortedHead;
			ListNode* sortedCur = sortedHead;
			while (sortedCur != nullptr && sortedCur->val > pNode->val)
			{
				sortedLast = sortedCur;
				sortedCur = sortedCur->next;
			}
			head = head->next;
			pNode->next = sortedCur;
			sortedLast->next = pNode;    
		}
	}
	ListNode* reverseNode = nullptr;
	while (sortedHead) 
	{
		ListNode* pCur = sortedHead;
		sortedHead = sortedHead->next;
		pCur->next = reverseNode;
		reverseNode = pCur;
	}
	return reverseNode;
}
