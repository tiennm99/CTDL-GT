#include <iostream>
using namespace std;
struct node {
	int data;
	node *next = NULL;
};
int myMaxFunc(node* head, int maxVal) {
	if (head == NULL)
	{
		return maxVal;
	}
	if (head->data > maxVal)
	{
		maxVal = head->data;
	}
	return myMaxFunc(head->next, maxVal);
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
	cout << myMaxFunc(head, INT_MIN) << endl;
	system("pause");
	return 0;
}