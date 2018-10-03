/*
Write a function:
1. Append a node to linked list.
2. Prepend a node to linked list.
3. Search and return pointer to node if existed otherwise, return NULL.
*/
#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
void appendList(node* &head, int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
void prependList(node* &head, int data)
{
	node* newNode = new node;
	newNode->data = data;
	if (head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}
node* searchNode(node* head, int val)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
node* searchLastNode(node* head, int val)
{
	node* temp = head;
	node* pos = NULL;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			pos = temp;
		}
		temp = temp->next;
	}
	return pos;
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
	node* head = NULL;
	for (int i = 0; i < 10; i++)
	{
		prependList(head, i);
	}
	for (int i = 0; i < 10; i++)
	{
		prependList(head, i);
	}
	cout << searchLastNode(head, 8);
	printAll(head);
	system("pause");
	return 0;
}