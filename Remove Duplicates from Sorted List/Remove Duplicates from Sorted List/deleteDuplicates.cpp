#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (NULL == head)
		return head;
	ListNode *node;
	node = head;
	while (node && node->next)
	{
		if (node->val == node->next->val)
			node->next = node->next->next;
		else
			node = node->next;
	}
	return head;
}

int main()
{
	ListNode *p1 = &ListNode(1);
	ListNode *p2 = &ListNode(1);
	ListNode *p3 = &ListNode(2);
	ListNode *p4 = &ListNode(3);
	ListNode *p5 = &ListNode(3);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	deleteDuplicates(p1);
	while (p1)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}
	return 0;
}