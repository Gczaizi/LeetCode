#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*ListNode* reverseList(ListNode* head)
{//递归
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	ListNode *p = head->next;
	ListNode *n = reverseList(p);
	head->next = NULL;
	p->next = head;
	return n;
}
*/
ListNode* reverseList(ListNode* head)
{//迭代
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *pre = head;
	ListNode *p = head->next;
	pre->next = NULL;
	ListNode *next;
	while (p != NULL)
	{
		next = p->next;
		p->next = pre;
		pre = p;
		p = next;
	}
	return pre;	//返回最后一个元素，此时 p == NULL
}


int main()
{
	ListNode *p1 = &ListNode(1);
	ListNode *p2 = &ListNode(2);
	ListNode *p3 = &ListNode(3);
	ListNode *p4 = &ListNode(4);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	ListNode *p = p1;
	while (p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	cout << endl;
	ListNode *re = reverseList(p1);
	ListNode *rp = re;
	while (rp != NULL)
	{
		cout << rp->val << endl;
		rp = rp->next;
	}
	return 0;
}