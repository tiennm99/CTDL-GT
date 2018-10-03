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
		cout << head->data << " ";
		printAll(head->next);
	}
}
void printAll2(node* head)
{
	if (head == NULL)
	{
		return;
	}
	node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}
void func1(node* head) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = head;
			return;
		}
		temp = temp->next;
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
	head->next = a;
	printAll(head);
	func1(head);
	printAll2(NULL);
	system("pause");
	return 0;
}