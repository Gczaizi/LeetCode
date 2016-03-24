#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head)
{
	if (NULL == head)
		return head;
	ListNode *odd = head;
	ListNode *evenHead = head->next;	//����һ��ż������ͷ
	ListNode *even = evenHead;		//ż������Ԫ��Ϊż������ͷ
	while (NULL != even && NULL != even->next)
	{
		odd->next = odd->next->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}

int main()
{
	ListNode *p1 = &ListNode(1);
	ListNode *p2 = &ListNode(2);
	ListNode *p3 = &ListNode(3);
	ListNode *p4 = &ListNode(4);
	ListNode *p5 = &ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	oddEvenList(p1);
	while (p1)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}
	return 0;
}