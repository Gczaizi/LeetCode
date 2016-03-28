#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *first, *second, *temp;
	//pre = head;
	first = head;
	second = first->next;
	head = second;	//需要记录头部
	temp = first;
	while (first && second)
	{
		temp->next = second;
		first->next = second->next;
		second->next = first;
		temp = first;
		first = first->next;
		if (first != NULL)
			second = first->next;
	}
	return head;
}

int main()
{
	ListNode *p1 = &ListNode(1);
	ListNode *p2 = &ListNode(2);
	ListNode *p3 = &ListNode(3);
	ListNode *p4 = &ListNode(4);
	ListNode *p5 = &ListNode(5);
	p1->next = NULL;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	p1 = swapPairs(p1);
	while (p1)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}
	return 0;
}