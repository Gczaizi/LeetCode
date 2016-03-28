#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoList(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoList(l2->next, l2);
		return l2;
	}
}
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *head = NULL;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	ListNode *p = head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	if (l1)
		p->next = l1;
	else
		p->next = l2;
	return head;
}

int main()
{
	ListNode *p1 = &ListNode(1);
	ListNode *p2 = &ListNode(2);
	ListNode *p3 = &ListNode(3);
	ListNode *p4 = &ListNode(4);
	ListNode *p5 = &ListNode(5);
	p1->next = p3;
	p2->next = p4;
	p3->next = p5;
	p4->next = NULL;
	p5->next = NULL;
	p5 = mergeTwoLists(p1, p2);
	while (p5)
	{
		cout << p5->val << endl;
		p5 = p5->next;
	}
	return 0;
}