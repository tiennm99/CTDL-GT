#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

void appendList(Node* &head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void makeCircularLinkedList(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = head;
			return;
		}
		temp = temp->next;
	}
}

void printSingleLinkedList(Node* head)
{
	if (head != NULL)
	{
		cout << head->data << " ";
		printSingleLinkedList(head->next);
	}
}

void printCircularLinkedList(Node* head)
{
	if (head == NULL) return;
	Node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}

void printList(Node* head)
{
	if (head == NULL) return;
	Node *temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != NULL && temp != head);
}

Node* searchList(Node* head, int data)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

Node* deleteNth(Node* head, int n)
{
	if (head == NULL || n < 0)
	{
		return head;
	}
	if (n == 0)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node *pre = head, *cur = head->next;
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

int main()
{
	Node* head = NULL;
	Node* search = NULL;
	for (int i = 0; i < 10; ++i)
	printSingleLinkedList(head);
	cout << endl;
	printList(head);
	cout << endl;
	search = searchList(head, 5);
	cout << (void*)search << endl;
	makeCircularLinkedList(head);
	printCircularLinkedList(head);	{
		appendList(head, i);
	}
	cout << endl;
	printList(head);
	cout << endl;
	system("pause");
	return 0;
}