#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *sTop;
    int sCount;
};

struct Queue {
    Node *qFront;
    Node *qRear;
    int qCount;
};

void createStack(Stack *&s)
{
    if (s != nullptr) {
        while (s->sTop != nullptr) {
            Node *temp = s->sTop;
            s->sTop = s->sTop->next;
            delete temp;
        }
        s->sCount = 0;
        delete s;
    }
    s = new Stack;
    s->sTop = nullptr;
    s->sCount = 0;
}

void pushStack(Stack *&s, int data)
{
    if (s == nullptr)
        return;
    Node *temp = new Node;
    if (temp == nullptr)
        return;
    temp->data = data;
    temp->next = s->sTop;
    s->sTop = temp;
    s->sCount++;
}

void popStack(Stack *&s)
{
    if (s == nullptr)
        return;
    if (s->sCount == 0)
        return;
    Node *temp = s->sTop;
    s->sTop = s->sTop->next;
    delete temp;
    s->sCount--;
}

int topStack(Stack *&s)
{
    if (s == nullptr)
        return 0;
    if (s->sCount == 0)
        return 0;
    return s->sTop->data;
}

bool isStackEmpty(Stack *s)
{
    if (s == nullptr)
        return true;
    return (s->sCount == 0);
}

bool isStackFull(Stack *s)
{
    Node *temp = new Node;
    if (temp != nullptr) {
        delete temp;
        return false;
    }
    return true;
}

void clearStack(Stack *&s)
{
    while (!isStackEmpty(s))
        popStack(s);
}

int sizeOfStack(Stack *s)
{
    if (s == nullptr)
        return -1;
    return s->sCount;
}

void createQueue(Queue *&q)
{
    if (q != nullptr) {
        while (q->qRear != nullptr) {
            Node *temp = q->qRear;
            q->qRear = q->qRear->next;
            delete temp;
        }
        while (q->qFront != nullptr) {
            Node *temp = q->qFront;
            q->qFront = q->qFront->next;
            delete temp;
        }
    }
    q = new Queue;
    q->qCount = 0;
    q->qFront = nullptr;
    q->qRear = nullptr;
}

void enqueue(Queue *&q, int data)
{
    if (q == nullptr)
        return;
    Node *temp = new Node;
    if (temp == nullptr)
        return;
    temp->next = q->qRear;
    temp->data = data;
    q->qRear = temp;
    if (q->qCount == 0)
        q->qFront = temp;
    q->qCount++;
}

void dequeue(Queue *&q)
{
    if (q == nullptr)
        return;
    if (q->qCount == 0)
        return;
    Node *temp = nullptr;
    if (q->qCount == 1) {
        q->qRear = nullptr;
    } else {
        temp = q->qRear;
        while (temp->next != q->qFront)
            temp = temp->next;
    }
    delete q->qFront;
    q->qFront = temp;
    q->qCount--;
}

int queueFront(Queue *q)
{
    if (q == nullptr)
        return 0;
    if (q->qCount == 0)
        return 0;
    return q->qFront->data;
}

int queueRear(Queue *q)
{
    if (q == nullptr)
        return 0;
    if (q->qCount == 0)
        return 0;
    return q->qRear->data;
}

bool isQueueEmpty(Queue *q)
{
    if (q == nullptr)
        return true;
    return (q->qCount == 0);
}

bool isQueueFull(Queue *q)
{
    Node *temp = new Node;
    if (temp != nullptr) {
        delete temp;
        return false;
    }
    return true;
}

void clearQueue(Queue *&q)
{
    while (!isQueueEmpty(q))
        dequeue(q);
}

int sizeOfQueue(Queue *q)
{
    if (q == nullptr)
        return -1;
    return q->qCount;
}

void stackToQueue(Stack *&s, Queue *&q)
{
    createQueue(q);
    while (!isStackEmpty(s)) {
        int x = topStack(s);
        popStack(s);
        enqueue(q, x);
    }
}

void queueToStack(Queue *&q, Stack *&s)
{
    createStack(s);
    if (!isQueueEmpty(q)) {
        Node *temp = q->qRear;
        while (temp != nullptr) {
            pushStack(s, temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    return 0;
}
