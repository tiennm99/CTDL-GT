#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next = NULL;
};
void printAll(node* head)
{
	if (head != NULL)
	{
		cout << head->data << endl;
		printAll(head->next);
	}
}
void fun2(node* head)
{
	if (head == NULL)
		return;
	printf("%d ", head->data);
	if (head->next != NULL)
		fun2(head->next->next);
	printf("%d ", head->data);
}
int main()
{
	node *a, *b, *c, *d, *e, *f, *g;
	node *head;
	g = new node();
	g->data = 17;
	g->next = NULL;
	f = new node();
	f->data = 5;
	f->next = g;
	e = new node();
	e->data = 13;
	e->next = f;
	d = new node();
	d->data = 6;
	d->next = e;
	c = new node();
	c->data = 3;
	c->next = d;
	b = new node();
	b->data = 5;
	b->next = c;
	a = new node();
	a->data = -11;
	a->next = b;
	head = new node();
	head->next = a;
	//printAll(head);
	fun2(c);
	//printAll(head);
	system("pause");
	return 0;
}