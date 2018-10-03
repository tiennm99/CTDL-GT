#include <iostream>
using namespace std;
struct node {
	int data;
	node *next = NULL;
};
node* deleteNth(node* head, int n)
{
	if (head == NULL || n < 0)
	{
		return head;
	}
	if (n == 0)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		node *pre = head, *cur = head->next;
		for (int i = 1; i < n; i++)
		{
			pre = cur;
			cur = cur->next;
			if (cur == NULL)
			{
				break;
			}
		}
		if (cur != NULL)
		{
			pre->next = cur->next;
			delete cur;
			cur = NULL;
		}
	}
	return head;
}
void printAll(node* head)
{
	if (head != NULL)
	{
		cout << head->data << " ";
		printAll(head->next);
	}
}
int main()
{
	node *a, *b, *c, *d, *e, *f, *g;
	node *head;
	g = new node();
	g->data = 7;
	g->next = NULL;
	f = new node();
	f->data = 2;
	f->next = g;
	e = new node();
	e->data = 100;
	e->next = f;
	d = new node();
	d->data = 3;
	d->next = e;
	c = new node();
	c->data = 9;
	c->next = d;
	b = new node();
	b->data = 5;
	b->next = c;
	a = new node();
	a->data = -11;
	a->next = b;
	head = new node();
	//head->data = 0;
	head->next = a;
	printAll(head);
	cout << endl;
	head = deleteNth(head, 7);
	printAll(head);
	system("pause");
	return 0;
}